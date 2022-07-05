/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:42:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 20:14:11 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>

typedef union u_color
{
	int	value;
	struct s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	}	rgb;
}	t_color;

typedef struct s_point_2d
{
	double	x;
	double	y;
}	t_point_2d;

typedef struct s_point_3d
{
	double	x;
	double	y;
	double	z;
}	t_point_3d;

typedef struct s_pixel
{
	t_point_2d	dim_2;
	t_point_3d	dim_3;
	t_color		color;
	int			drawable;
}	t_pixel;


typedef struct s_map
{
	size_t		height;
	size_t		width;
	t_pixel		**data;
	t_point_3d	max_edge;
	t_point_3d	min_edge;
}	t_map;

#endif
