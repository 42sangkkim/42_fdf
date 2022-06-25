/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:34:59 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 20:02:37 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	init_mlx(t_fdf fdf)
{
	t_mlx	mlx;
	int		screen_width;
	int		screen_height;

	mlx.mlx_ptr = mlx_init();
	if (!(mlx.mlx_ptr))
		return (NULL);
	screen_width = (int)((double)(max.x + max.y) * COS30);
	screen_height = max.z + 
		(int)((double)(max.x + max.y) * SIN30) + min.z;
	fdf.origin.x = (int)(((double)max.x * COS30) + (width * PADDING * 0.5));
	fdf.origin.y = max.z + (int)(height * PADDING * 0.5);
	fdf.origin.color = 0;
	screen_width = (int)((double)screen_width * (1 + PADDING));
	screen_hright = (int)((double)screen_height * (1 + PADDING));
	mlx.win_ptr = mlx_new_window(my_mlx.mlx_ptr,
		screen_width, screen_height, TITLE);
	if (!(mlx.win_ptr))
	{
		//free(mlx.mlx_ptr);
		return (NULL);
	}
	return (mlx);
}

// init window and return the origin
t_pixel	init_window(t_mlx *my_mlx, t_pixel max, t_pixel min);
{
	int 	width;
	int 	height;
	t_pixel	origin;

	width = (int)((double)(max.x + max.y) * COS30);
	height = max.z + 
		(int)((double)(max.x + max.y) * SIN30) + min.z;
	origin.x = (int)(((double)max.x * COS30) + (width * PADDING * 0.5));
	origin.y = max.z + (int)(height * PADDING * 0.5);
	origin.color = 0;
	width = (int)((double)width * (1 + PADDING));
	hright = (int)((double)height * (1 + PADDING));
	my_mlx.win_ptr = mlx_new_window(my_mlx.mlx_ptr,
		width, height, "sangkkim fdf");
	return (origin);
}
