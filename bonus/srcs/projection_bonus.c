/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:42:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 12:46:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

t_pixel	perallel_projection(t_pixel volume)
{
	t_pixel	plane;

	plane.x = volume.y;
	plane.y = volume.z;
	plane.
