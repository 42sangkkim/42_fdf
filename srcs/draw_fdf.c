/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:06:33 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 19:06:15 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "fdf.h"

void	draw_line(t_mlx mlx, t_pixel p1, t_pixel p2);
int		get_gradation(int c1, int c2, double ratio);

void	draw_fdf(t_mlx mlx, t_fdf fdf)
{
	int	x;
	int	y;

	mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
	x = 0;
	y = 0;
	while (x <= fdf.width)
	{
		y = 0;
		while (y <= fdf.height)
		{
			if (x != fdf.width)
				draw_line(mlx, fdf.dots[x][y], dots[x + 1][y]);
			if (y != fdf.height)
				draw_line(mlx, fdf.dots[x][y], dots[x][y + 1]);
			y++;
		}
		x++;
	}
}

void	draw_line(t_mlx mlx, t_pixel p1, t_pixel p2)
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
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr,
			(int)pixel[0], (int)pixel[1],
			get_gradation(p1.color, p2.color, ratio));
		pixel[0] += d_pixel[0];
		pixel[1] += d_pixel[1];
		ratio += d_ratio;
	}
}

int	get_gradation(int c1, int c2, double ratio)
{
	int		color;
	double	r;
	double	g;
	double	b;

	r = fma((double)(c1 & 0xFF0000 >> 16), 1 - ratio, 0)
		+ fma((double)(c2 & 0xFF0000 >> 16), ratio, 0);
	g = fma((double)(c1 & 0x00FF00 >> 8), 1 - ratio, 0)
		+ fma((double)(c2 & 0x00FF00 >> 8), ratio, 0);
	b = fma((double)(c1 & 0x0000FF), 1 - ratio, 0)
		+ fma((double)(c2 & 0x0000FF), ratio, 0);
	color = ((int)r << 16) + ((int)g << 8) + (int)b;
	return (color);
}
