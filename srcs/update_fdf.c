/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:04:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 19:48:22 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>

#include "fdf.h"
#include "config.h"

t_point	transform(t_point from, t_transform tr,
			t_point (*projection)(t_point));
t_point	isometric_projection(t_point from);

void	update_fdf(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	fdf -> tr.sin = sin(
			(double)(fdf -> tr.rotate) * 2 * PI / ROTATE_RESOLUTION);
	fdf -> tr.cos = cos(
			(double)(fdf -> tr.rotate) * 2 * PI / ROTATE_RESOLUTION);
	i = 0;
	while (i < fdf -> height)
	{
		j = 0;
		while (j < fdf -> width)
		{
			fdf -> screen[i][j] = transform(fdf -> volume[i][j],
					fdf -> tr, &isometric_projection);
			j++;
		}
		i++;
	}
}

t_point	transform(t_point from, t_transform tr,
	t_point (*projection)(t_point))
{
	t_point	to;

	to.x = tr.cos * from.x - tr.sin * from.y;
	to.y = tr.sin * from.x + tr.cos * from.y;
	to.z = tr.altitude * from.z;
	to = projection(to);
	to.x = (to.x * tr.zoom) + tr.translate.x + (SCREEN_WIDTH / 2);
	to.y = -(to.y * tr.zoom) + tr.translate.y + (SCREEN_HEIGHT / 2);
	to.color = from.color;
	return (to);
}

t_point	isometric_projection(t_point from)
{
	t_point	to;

	to.x = COS30 * (from.y - from.x);
	to.y = from.z - SIN30 * (from.x + from.y);
	to.z = 0;
	to.color = from.color;
	return (to);
}
