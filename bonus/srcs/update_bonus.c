/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:47:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 20:44:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int		transform(t_point_2d *dim_2, t_point_3d dim_3, t_transform tr);
void	perallel_projection(t_point_2d *dim_2, t_point_3d dim_3);
int		one_point_projection(t_point_2d *dim_2, t_point_3d dim_3, double fov);

void	update(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			if (transform(&(fdf->map.data[i][j].dim_2),
					fdf->map.data[i][j].dim_3,
					fdf->transform) == -1)
				fdf->map.data[i][j].drawable = 0;
			else
				fdf->map.data[i][j].drawable = 1;
			j++;
		}
		i++;
	}
}

int	transform(t_point_2d *dim_2, t_point_3d dim_3, t_transform tr)
{
	// z_gain
	dim_3.z *= tr.z_gain;
	// rotate

	// projection
	if (tr.mode == PERALLEL)
		perallel_projection(dim_2, dim_3);
	else if (tr.mode == ONE_POINT)
	{
		if (one_point_projection(dim_2, dim_3, tr.fov) == -1)
			return (-1);
	}
	// zoom
	dim_2->x *= tr.zoom;
	dim_2->y *= -tr.zoom;
	// translate
	dim_2->x += tr.ox + SCREEN_WIDTH / 2;
	dim_2->y += tr.oy + SCREEN_HEIGHT / 2;
	return (0);
}

void	perallel_projection(t_point_2d *dim_2, t_point_3d dim_3)
{
	dim_2->x = dim_3.y;
	dim_2->y = dim_3.z;
}

int	one_point_projection(t_point_2d *dim_2, t_point_3d dim_3, double fov)
{
	double		distance;

	distance = fov - dim_3.x;
	if (distance <= 0)
		return (-1);
	else
	{
		dim_2->x = dim_3.y / distance;
		dim_2->y = dim_3.z / distance;
		return (0);
	}
}
