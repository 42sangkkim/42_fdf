/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:25:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 20:33:50 by sangkkim         ###   ########.fr       */
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

	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			isometric_projection(&(fdf->plane[i][j]), fdf->volume[i][j]);
			j++;
		}
		i++;
	}
}

void	isometric_projection(t_pixel *to, t_pixel from)
{
	const double	cos30 = cos(M_PI / 6);
	const double	sin30 = sin(M_PI / 6);

	to->x = from.x * -cos30 + from.y * cos30;
	to->y = from.x * -sin30 + from.y * -sin30 + from.z;
	to->color = from.color;
}
