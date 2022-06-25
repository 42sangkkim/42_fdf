/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:34:59 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 21:24:03 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "../incs/fdf.h"

void	get_screen_size(int *width, int *height, t_fdf fdf);
int		get_dh(t_fdf fdf);

t_mlx	init_mlx(t_fdf fdf)
{
	t_mlx	mlx;
	int		screen_width;
	int		screen_height;

	mlx.mlx_ptr = mlx_init();
	if (!(mlx.mlx_ptr))
	{
		mlx.mlx_ptr = NULL;
		mlx.win_ptr = NULL;
		return (mlx);
	}
	get_screen_size(&screen_width, &screen_height, fdf);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			screen_width, screen_height, TITLE);
	if (!(mlx.win_ptr))
	{
		mlx.mlx_ptr = NULL;
		return (mlx);
	}
	return (mlx);
}

void	get_screen_size(int *width, int *height, t_fdf fdf)
{
	int	dh;
	int	dw;

	dw = fdf.width + fdf.height;
	dh = get_dh(fdf);
	*screen_width = (int)((double)dw * COS30 * (1 + PADDING));
	*screen_height = (int)(((double)dz + (double)dw * SIN30) * (1 + PADDING));
}

int	get_dh(t_fdf fdf)
{
	int	max;
	int	min;
	int	x;
	int	y;

	max = fdf.edges[0][0];
	min = fdf.edges[0][0];
	x = 0;
	while (x < fdf.width)
	{
		y = 0;
		while (y < fdf.height)
		{
			if (max < fdf.edges[x][y])
				max = fdf.edges[x][y];
			if (min > fdf.edges[x][y])
				min = fdf.edges[x][y];
			y++;
		}
		x++;
	}
	return (max - min);
}
