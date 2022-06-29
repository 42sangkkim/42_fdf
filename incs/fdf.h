/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 19:46:38 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

# define COS30 0.86602540
# define SIN30 0.5
# define PI 3.141592

# define KEY_ESC 53
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_MINUS 27
# define KEY_PLUS 24

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDDLE 3
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

struct s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
};

typedef union u_color
{
	int				value;
	struct s_rgb	rgb;
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}	t_point;

typedef struct s_transform
{
	size_t	rotate;
	t_point	translate;
	double	zoom;
	double	altitude;
	double	sin;
	double	cos;
}	t_transform;

typedef struct s_fdf
{
	size_t		width;
	size_t		height;
	t_point		**volume;
	t_point		**screen;
	int			rotating;
	t_transform	tr;
}	t_fdf;

#endif
