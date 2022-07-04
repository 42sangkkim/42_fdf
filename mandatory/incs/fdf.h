/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:42:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 00:09:23 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <pixel.h>

// CONFIG

# define MIN_COLOR 0xFFFFFF
# define MAX_COLOR 0xFF005F
# define ZOOM 20

// STRUCT

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		screen_width;
	int		screen_height;
}	t_mlx;

typedef struct s_fdf
{
	t_mlx	mlx;
	size_t	height;
	size_t	width;
	t_pixel	**volume;
	t_pixel	**plane;
	t_pixel	min_edge;
	t_pixel	max_edge;
}	t_fdf;

#endif
