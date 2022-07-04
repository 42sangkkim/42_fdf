/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:42:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 00:34:14 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

// CONFIG

# define MIN_COLOR 0xFFFFFF
# define MAX_COLOR 0xFF005F
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

// STRUCT

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

typedef struct s_pixel
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}	t_pixel;

typedef struct s_quaternion
{
	double	w;
	double	x;
	double	y;
	double	z;
}	t_quaternion;

typedef struct s_transform
{
	double			zoom;
	double			z_gain;
	t_pixel			translate;
	t_quaternion	rotate;
}	t_transform;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_fdf
{
	t_mlx		mlx;
	size_t		height;
	size_t		width;
	t_pixel		**volume;
	t_pixel		**plane;
	t_pixel		min_edge;
	t_pixel		max_edge;
	t_transform	transform;
}	t_fdf;

#endif

