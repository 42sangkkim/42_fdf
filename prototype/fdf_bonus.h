/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:21:15 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 21:02:02 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "config_bonus.h"
# include "map_bonus.h"
# include "transform_bonus.h"

# define EVENT_CLOSE			17

# define KEY_ESC				-1
# define KEY_PLUS				-1
# define KEY_MINUS				-1
# define KEY_UP_ARROW			-1
# define KEY_DOWN_ARROW			-1
# define KEY_LEFT_ARROW			-1
# define KEY_RIGHT_ARROW		-1
# define KEY_1					-1
# define KEY_2					-1
# define KEY_Q					-1
# define KEY_W					-1
# define KEY_E					-1
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define BUTTON_SCROLL_UP		4
# define BUTTON_SCROLL_DOWN		5

# define PERALLEL_PROJECTION	0
# define ONE_POINT_PROJECTION	1

typedef struct s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_transform	transform;
	int			projection;
	t_point3	axis[3];
}	t_fdf;

#endif