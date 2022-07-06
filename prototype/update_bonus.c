/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:18:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 21:01:46 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf_bonus.h"

void	generate_rot_vector(double *vector[3][3], t_quaternion quaternion);
void	transform(t_edge *edge, double vector[3][3], t_transform tr, int mode);
void	perallel_projection(t_point2 *d2, t_point3 d3);
int		one_point_projection(t_point2 *d2, double fov, t_point3 d3);

void	update(t_fdf *fdf)
{
	size_t		i;
	size_t		j;
	double		rot_vector[3][3];
	t_point2	d2;
	t_point3	d3;

	generate_rot_vector(&rot_vector, fdf->transform.quaternion);
	i = 0;
	while (i < fdf->map.height)
	{
		j = 0;
		while (j < fdf->map.width)
		{
			transform(&(fdf->map.edges[i][j]),
				rot_vector, fdf->transform, fdf->projection);
			j++;
		}
		i++;
	}
	update_axis(&(fdf->axis), rot_vector);
}

void	generate_rot_vector(double *vector[3][3], t_quaternion quaternion)
{
	double	temp[4][4];

	temp[0][0] = quaternion.w * quaternion.w;
	temp[0][1] = quaternion.w * quaternion.x;
	temp[0][2] = quaternion.w * quaternion.y;
	temp[0][3] = quaternion.w * quaternion.z;
	temp[1][1] = quaternion.x * quaternion.x;
	temp[1][2] = quaternion.x * quaternion.y;
	temp[1][3] = quaternion.x * quaternion.z;
	temp[2][2] = quaternion.y * quaternion.y;
	temp[2][3] = quaternion.y * quaternion.z;
	temp[3][3] = quaternion.z * quaternion.z;
	*vector[0][0] = 1. - 2. * temp[2][2] - 2. * temp[3][3];
	*vector[0][1] = 2. * temp[1][2] - 2. * temp[0][3];
	*vector[0][2] = 2. * temp[1][3] + 2. * temp[0][2];
	*vector[1][0] = 2. * temp[1][2] + 2. * temp[0][3];
	*vector[1][1] = 1. - 2. * temp[1][1] - 2. * temp[3][3];
	*vector[1][2] = 2. * temp[2][3] - 2. * temp[0][1];
	*vector[2][0] = 2. * temp[1][3] - 2. * temp[0][2];
	*vector[2][1] = 2. * temp[2][3] + 2. * temp[0][1];
	*vector[2][2] = 1. - 2. * temp[1][1] - 2. * temp[2][2];
}

void	transform(t_edge *edge, double vector[3][3], t_transform tr, int mode)
{
	t_point3	tmp3;
	t_point2	tmp2;

	tmp3 = vector_product(vector, edge->d3);
	if (mode == PERALLEL_PROJECTION)
		perallel_projection(&tmp2, tmp3);
	else
	{
		if (!one_point_projection(&tmp2, tr.fov, tmp3))
		{
			edge->drawable = 0;
			return ;
		}
	}
	edge->drawable = 1;
	edge->d2.x = tmp2.x * tr.zoom + tr.dx + (double)SCREEN_WIDTH / 2;
	edge->d2.y = -tmp2.y * tr.zoom - tr.dy + (double)SCREEN_HEIGHT / 2;
}

t_point3	vector_product(double vector[3][3], t_point3 from)
{
	t_point3	to;

	to.x = vector[0][0] * from.x + vector[0][1] * from.y
		+ vector[0][2] * from.z;
	to.y = vector[1][0] * from.x + vector[1][1] * from.y
		+ vector[1][2] * from.z;
	to.z = vector[2][0] * from.x + vector[2][1] * from.y
		+ vector[2][2] * from.z;
	return (to);
}

void	update_axis(t_point3 *axis[3], double rot_vector[3][3])
{
	(*axis)[0].x = rot_vector[0][0] * AXIS_LEN;
	(*axis)[0].y = rot_vector[1][0] * AXIS_LEN;
	(*axis)[0].z = rot_vector[2][0] * AXIS_LEN;
	(*axis)[1].x = rot_vector[0][1] * AXIS_LEN;
	(*axis)[1].y = rot_vector[1][1] * AXIS_LEN;
	(*axis)[1].z = rot_vector[2][1] * AXIS_LEN;
	(*axis)[2].x = rot_vector[0][2] * AXIS_LEN;
	(*axis)[2].y = rot_vector[1][2] * AXIS_LEN;
	(*axis)[2].z = rot_vector[2][2] * AXIS_LEN;
}
