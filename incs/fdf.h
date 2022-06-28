/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 23:25:34 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define COS30 0.86602540
# define SIN30 0.5

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}	t_point;

typedef	struct s_transform
{
	double	rotate;
	t_point	translate;
	double	zoom;
	double	altitude;	
}	t_transform;

typedef struct s_fdf
{
	size_t		width;
	size_t		height;
	t_point		**volume;
	t_point		**screen;
	t_transform	tr;
}	t_fdf;

#endif
