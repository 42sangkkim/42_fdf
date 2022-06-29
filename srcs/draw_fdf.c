/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:06:33 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 03:28:34 by sangkkim         ###   ########.fr       */
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
	int	x;
	int	y;

	mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
	x = 0;
	y = 0;
	while (x < fdf -> width)
	{
		y = 0;
		while (y < fdf -> height)
		{
			if (x)
				draw_line(mlx, fdf -> screen[x - 1][y], fdf -> screen[x][y]);
			if (y)
				draw_line(mlx, fdf -> screen[x][y - 1], fdf -> screen[x][y]);
			y++;
		}
		x++;
	}
}

void	draw_line(t_mlx *mlx, t_point p1, t_point p2)
{
	size_t	i;
	size_t	dt;
	t_point	pixel;
	t_point	delta;

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
