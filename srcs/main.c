/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:55:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 02:55:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <mlx.h>

#include <fdf.h>
#include <utils.h>

void	init(t_mlx *mlx, t_fdf *fdf, char *file_name);
int		update(void *param);
int		key_hook(int keycode, void *param);

void	head1_fdf(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_fdf	fdf;
	void	*param[2];

	if (argc != 2)
		exit_msg(-1, "fdf accept just one parameter");
	init(&mlx, &fdf, argv[1]);
	param[0] = &mlx;
	param[1] = &fdf;
	// update(&fdf);
	// draw(&mlx, &fdf);
	mlx_key_hook(mlx.win_ptr, &key_hook, param);
	mlx_loop_hook(mlx.mlx_ptr, &update, param);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	return (0);
}

#include <stdio.h>
#include <config.h>
void	head1_fdf(t_fdf *fdf)
{
	size_t	i;

	printf("height : %lu, width : %lu\n", fdf -> height, fdf -> width);
	i = 0;
	while (fdf -> volume[i])
	{
		printf("x : %2.2f, y : %2.2f, z : %2.2f, color : %X\n",
			fdf -> volume[i][0].x,
			fdf -> volume[i][0].y,
			fdf -> volume[i][0].z,
			fdf -> volume[i][0].color);
		i++;
	}
}
