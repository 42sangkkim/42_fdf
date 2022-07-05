/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:36:13 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 20:14:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx.h"
#include "fdf_bonus.h"
#include "utils_bonus.h"

void	draw_fdf(t_fdf *fdf);
void	draw_line(t_mlx mlx, t_pixel p1, t_pixel p2);
void	draw_guide(t_fdf *fdf);
void	draw_status(t_fdf *fdf);

#include <unistd.h>
void	draw(t_fdf *fdf)
{
	write(1, "draw\n", 5);
	mlx_clear_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
	draw_fdf(fdf);
	draw_guide(fdf);
	draw_status(fdf);
}

void	draw_fdf(t_fdf *fdf)
{
	size_t	i;
	size_t	j;
	t_pixel	**data;

	data = fdf->map.data;
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			if (i)
				draw_line(fdf->mlx, data[i - 1][j], data[i][j]);
			if (j)
				draw_line(fdf->mlx, data[i][j - 1], data[i][j]);
			j++;
		}
		i++;
	}
}

void	draw_line(t_mlx mlx, t_pixel p1, t_pixel p2)
{
	size_t		i;
	size_t		dt;
	t_point_2d	point;
	t_point_2d	delta;

	if (!p1.drawable || !p2.drawable)
		return ;
	point.x = p1.dim_2.x;
	point.y = p1.dim_2.y;
	dt = (size_t)fmax(
			fabs(p2.dim_2.x - p1.dim_2.x),
			fabs(p2.dim_2.y - p1.dim_2.y));
	delta.x = (p2.dim_2.x - p1.dim_2.x) / (double)dt;
	delta.y = (p2.dim_2.y - p1.dim_2.y) / (double)dt;
	i = 0;
	while (i <= dt)
	{
		mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr,
			(int)point.x, (int)point.y,
			mix_color(p1.color, p2.color, (double)i / (double)dt).value);
		point.x += delta.x;
		point.y += delta.y;
		i++;
	}
}

void	draw_guide(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 0, GUIDE_COLOR,
			"Arrows : move");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 20, GUIDE_COLOR,
			"Mouse wheel : zoom in/out");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 40, GUIDE_COLOR,
			"Q E : rotate x-axis");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 60, GUIDE_COLOR,
			"A S : rotate y-axis");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 80, GUIDE_COLOR,
			"Z X : rotate z-axis");
	if (fdf->transform.mode == PERALLEL)
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 100,
				GUIDE_COLOR, "mode : perallel projection");
	else
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 100,
				GUIDE_COLOR, "mode : one point projection");
}

void	draw_status(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 520, GUIDE_COLOR,
			"FOV    : 100.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 540, GUIDE_COLOR,
			"z_gain : 1.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 560, GUIDE_COLOR,
			"zoom   : 15.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 580, GUIDE_COLOR,
			"Quaternion");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 600, GUIDE_COLOR,
			"    x  : 0.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 620, GUIDE_COLOR,
			"    y  : 0.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 640, GUIDE_COLOR,
			"    z  : 0.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 660, GUIDE_COLOR,
			"tanslate");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 680, GUIDE_COLOR,
			"    x  : 0.0");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 700, GUIDE_COLOR,
			"    y  : 0.0");
}
