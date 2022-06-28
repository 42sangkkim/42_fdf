/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 03:32:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>

# define COS30 0.86602540
# define SIN30 0.5
# define PI 3.141592

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
	double	rotate;
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
