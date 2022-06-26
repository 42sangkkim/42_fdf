/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:48:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 18:14:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point	transform(t_point from, t_transform tf)
{
	t_point	to;

	to = rotate(from, tf.rotate);
	to = translate(to, tf.translate);
	to = zoom(to, tf.zoom);
	return (to);
}

t_point	rotate(t_point from, double rotate)
{
	t_point	to;

	to.x = (from.x * fcos(rotate)) - (y * fsin(rotate));
	to.y = (from.x * fsin(rotate)) + (y * fcos(rotate));
	to.z = from.z;
	return (to);
}

t_point translate(t_point to, t_point translate)
{
	t_point	to;

	to.x = from.x + translate.x;
	to.y = from.y + translate.y;
	to.z = from.z + translate.z;
}
