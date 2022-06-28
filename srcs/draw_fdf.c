/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:06:33 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 02:02:57 by sangkkim         ###   ########.fr       */
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
	int		dt;
	double	pixel[2];
	double	d_pixel[2];
	double	ratio;
	double	d_ratio;

	pixel[0] = (double)p1.x;
	pixel[1] = (double)p1.y;
	ratio = 0;
	dt = (int)fabs(fmax((double)(p2.x - p1.x), (double)(p2.y - p1.y)));
	d_pixel[0] = (double)(p2.x - p1.x) / (double)dt;
	d_pixel[1] = (double)(p2.y - p1.y) / (double)dt;
	d_ratio = 1 / (double)dt;
	dt++;
	while (dt--)
	{
		mlx_pixel_put(mlx -> mlx_ptr, mlx -> win_ptr,
			(int)pixel[0], (int)pixel[1],
			color_picker(p1.color, p2.color, ratio));
		pixel[0] += d_pixel[0];
		pixel[1] += d_pixel[1];
		ratio += d_ratio;
	}
}
