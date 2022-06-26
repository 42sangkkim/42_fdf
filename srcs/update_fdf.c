/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:04:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 18:58:33 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
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

void	volume_to_plane(t_point **edges, t_fdf fdf, t_point (*project)(t_point))
{
	const double	pi = 3.141592;
	size_t			i;
	size_t			j;

	fdf.tr.sin = fsin((double)(fdf.tr.rotate) * 2 * pi / RESOLUTION);
	fdf.tr.cos = fcps((double)(fdf.tr.rotate) * 2 * pi / RESOLUTION);
	i = 0;
	while (i < fdf.height)
	{
		j = 0;
		while (j < fdf.width)
		{
			edges[i][j] = transform(fdf.map[i][j], fdf.tr, project);
		}
	}
}

t_point	transform(t_point p_3d, t_translate tr, t_point (*project)(t_point))
{
	t_point	p_2d;

	p_3d = rotate(p3d, tr.sin, tr.cos, tr.alt);
	p_2d = project(p_3d);
	p_2d = translate(p_2d, tr.dx, tr.dy, tr.zoom);
	return (p_2d);
}

t_point	rotate(t_point from, double sin, double cos, double alt)
{
	t_point	to;

	to.x = (from.x * cos) - (from.y * sin);
	to.y = (from.x * sin) + (from.y * cos);
	to.z = (from.z * alt);
	to.color = from.color;
	return (to);
}

t_point	translate(t_point from, double dx, double dy, double zoom)
{
	t_point	to;

	to.x = (from.x + dx) * zoom;
	to.y = (from.y + dy) * zoom;
	to.z = 0;
	to.color = from.color;
	return (to);
}
