/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:04:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 19:18:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pixel	volume2plane(int x, int y, int z);
t_pixel	plane2window(t_pixel plane_pos, t_pixel origin);

int	update_fdf(t_fdf fdf)
{
	static t_pixel	origin;
	int				x;
	int				y;
	t_pixel			tmp;

	if (!ft_memcmp(origin, fdf.origin, sizeof(fdf)))
		return (0);
	origin = fdf.origin;
	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			tmp = volume2plane(x, y, fdf.edges[x][y]);
			fdf.dot[x][y] = plane2window(tmp, fdf.origin);
			y++;
		}
		x++;
	}
}

t_pixel	volume2plane(int x, int y, int z)
{
	t_pixel	plane_pos;

	plane_pos.x = (int)((double)(x - y) * COS30);
	plane_pos.y = (int)((double)(x + y) * SIN30) + z;
	plane_pos.color = set_color(z);
	return (pixel);
}

t_pixel	plane2window(t_pixel plane_pos, t_pixel origin)
{
	t_pixel	window_pos;

	window_pos.x = origin.x + plane_pos.x;
	window_pos.y = origin.y - plane_pos.y;
	window_pos.color = plane_pos.color;
	return (window_pos);
}
