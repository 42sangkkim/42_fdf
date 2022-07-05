/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:05:38 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 18:05:18 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_BONUS_H
# define TRANSFORM_BONUS_H

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quaternion;

typedef struct s_transform
{
	double			fov;
	double			zoom;
	double			z_gain;
	t_quaternion	quaternion;
	double			ox;
	double			oy;
	unsigned int	mode;
}	t_transform;

#endif
