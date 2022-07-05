/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:25:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 12:21:43 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "libft.h"
#include "fdf.h"

void	isometric_projection(t_pixel *to, t_pixel from);

void	transform(t_fdf *fdf)
{
	size_t	i;
	size_t	j;
	t_point	tmp;

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			tmp = rotate(fdf->volume[i][j], fdf->transform.rotate);
			tmp = plaperallel_projection(tmp);
			fdf->plane[i][j] = translate(tmp, fdf->transform);
			j++;
		}
		i++;
	}
}

t_pixel	rotate(t_pixel from, t_quaternion quaternion)
{
	t_pixel	to;

	return (to);
}

t_pixel	perallel_projection(t_pixel from)
{
	t_pixel	to;

	to.x = from.y;
	to.y = from.z;
	to.z = 0.;
	to.color = from.color;
}

t_pixel	translate(t_pixel from, t_transform transform)
{
	t_pixel	to;

	to.x = (from.x + transform.translate.x) * transform.zoom;
	to.y = (from.y + transform.translate.y) * transform.zoom;
	to.color = from.color;
	return (to);
}
