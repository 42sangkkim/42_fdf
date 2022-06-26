/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 17:34:29 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define COS30 0.86602540
# define SIN30 0.5

# define PADDING 0.2
# define TITLE "sangkkim fdf"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_width;
	int		screen_height;
}	t_mlx;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_map
{
	size_t	width;
	size_t	height;
	t_point	**data;
}	t_map;

typedef	struct s_transform
{
	double	rotate;
	double	x_offset;
	double	y_offset;
	double	z_offset;
}	t_transform;

#endif
