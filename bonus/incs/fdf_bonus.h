/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:42:58 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 19:38:20 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <stdlib.h>
# include "map_bonus.h"
# include "transform_bonus.h"

// CONFIG

# define MIN_COLOR		0xFFFFFF
# define MAX_COLOR		0xFF005F
# define GUIDE_COLOR	0xFFFFFF
# define SCREEN_WIDTH	1280
# define SCREEN_HEIGHT	720

# define D_TRANSLATE	2.0
# define D_GAIN			1.5
# define D_ZOOM			1.2
# define D_ROTATE		1.0
# define D_FOV			2.5

# define PERALLEL		0
# define ONE_POINT		1

// STRUC

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_fdf
{
	t_mlx		mlx;
	t_map		map;
	t_transform	transform;
}	t_fdf;

#endif
