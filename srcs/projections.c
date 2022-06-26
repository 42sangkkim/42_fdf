/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:58:16 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 19:05:52 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point	isometric_projection(t_point p_3d)
{
	t_point			p_2d;
	const double	sin30 = 0.5;
	const double	cos30 = 0.866025;

	p_2d.x = (p_3d.y - p_3d.x) * cos30;
	p_2d.y = p_3d.z - ((p_3d.x + p_3d.y) * sin30);
	p_2d.x = 0;
	p_2d.color = p_3d.color;
	return (p_2d);
}

t_point	perallel_projection(t_point p_3d);

t_point	iconic_projection(t_point p_3d);
