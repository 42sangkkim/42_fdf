/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:55:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 03:30:57 by sangkkim         ###   ########.fr       */
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
	mlx_key_hook(mlx.win_ptr, &key_hook, param);
	mlx_loop_hook(mlx.mlx_ptr, &update, param);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr);
	return (0);
}
