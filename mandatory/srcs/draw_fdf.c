/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:36:13 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 23:11:15 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx.h"
#include "fdf.h"
#include "utils.h"

void	translate_origin(t_fdf *fdf);
void	draw_line(t_mlx mlx, t_pixel p1, t_pixel p2);

void	draw_fdf(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	translate_origin(fdf);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (i)
				draw_line(fdf->mlx, fdf->plane[i - 1][j], fdf->plane[i][j]);
			if (j)
				draw_line(fdf->mlx, fdf->plane[i][j - 1], fdf->plane[i][j]);
			j++;
		}
		i++;
	}
}

void	translate_origin(t_fdf *fdf)
{
	double	ox;
	double	oy;
	size_t	i;
	size_t	j;

	ox = (double)fdf->mlx.screen_width / 2;
	oy = (double)fdf->mlx.screen_height / 2;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->plane[i][j].x *= ZOOM;
			fdf->plane[i][j].x += ox;
			fdf->plane[i][j].y *= -ZOOM;
			fdf->plane[i][j].y += oy;
			j++;
		}
		i++;
	}
}

void	draw_line(t_mlx mlx, t_pixel p1, t_pixel p2)
{
	size_t	i;
	size_t	dt;
	t_pixel	pixel;
	t_pixel	delta;

	pixel.x = p1.x;
	pixel.y = p1.y;
	dt = (size_t)fmax(fabs(p2.x - p1.x), fabs(p2.y - p1.y));
	delta.x = (p2.x - p1.x) / (double)dt;
	delta.y = (p2.y - p1.y) / (double)dt;
	i = 0;
	while (i <= dt)
	{
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr,
			(int)pixel.x, (int)pixel.y,
			mix_color(p1.color, p2.color, (double)i / (double)dt).value);
		pixel.x += delta.x;
		pixel.y += delta.y;
		i++;
	}
}
