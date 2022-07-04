/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:06:33 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/01 20:49:43 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

#include <fdf.h>
#include <config.h>
#include <utils.h>

void	draw_line(t_mlx *mlx, t_point p1, t_point p2);

void	draw_fdf(t_mlx *mlx, t_fdf *fdf)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (x < fdf->mlx.screen_height)
	{
		y = 0;
		while (y < fdf->mlx.width)
		{
			if (x)
				draw_line(mlx, fdf->map_2d.data[x - 1][y], fdf->map_2d.data[x][y]);
			if (y)
				draw_line(mlx, fdf->map_2d.data[x][y - 1], fdf->map_2d.data[x][y]);
			y++;
		}
		x++;
	}
}

void	draw_line(t_mlx *mlx, t_pixel p1, t_pixel p2)
{
	size_t	i;
	size_t	dt;
	t_pixel	pixel;
	t_pixel	delta;

	pixel.x = p1.x;
	pixel.y = p1.y;
	dt = (int)fmax(fabs(p2.x - p1.x), fabs(p2.y - p1.y));
	delta.x = (p2.x - p1.x) / (double)dt;
	delta.y = (p2.y - p1.y) / (double)dt;
	i = 0;
	while (i <= dt)
	{
		mlx_pixel_put(mlx -> mlx_ptr, mlx -> win_ptr,
			(int)pixel.x, (int)pixel.y,
			color_picker(p1.color, p2.color, (double)i / (double)dt).value);
		pixel.x += delta.x;
		pixel.y += delta.y;
		i++;
	}
}
