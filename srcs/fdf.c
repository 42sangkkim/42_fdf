/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:38:19 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 21:23:02 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	init_fdf(int argc, char **argv);
t_mlx	init_mlx(t_fdf fdf);
void	update_fdf(t_fdf fdf);
void	draw_fdf(t_mlx mlx, t_fdf fdf);

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_mlx	mlx;

	fdf = init_fdf(argc, argv);
	mlx = init_mlx(fdf);
	update_fdf(fdf);
	draw_fdf(mlx, fdf);
	// hooks
	mlx_loop(mlx.mlx_ptr);
	close_window(fdf, mlx, 0);
}

void	close_window(t_fdf fdf, t_mlx mlx, int code)
{
	free(fdf.dots);
	free(fdf.edges);
	mlx_destroy_window(mlx.win_ptr);
	exit(code);
}
