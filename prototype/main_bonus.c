/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:20:28 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 20:54:53 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"

int	key_hook(int keycode, void *param);
int	close_hook(void *param);
int	mouse_hook(int button, int x, int y, void *param);
int	loop_hook(void *param);

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	char	***file_data;

	if (argc != 2)
	{
		write(1, "fdf get one parameter, which is filename\n", 41);
		return (0);
	}
	file_data = get_file_data(argv[1]);
	if (!check_file_data(file_data))
		return (0);
	init_fdf(&fdf, file_data);
	free_double_array(file_data);
	init_mlx(&fdf, argv[1]);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

void	init_fdf(t_fdf *fdf, char **file_data)
{
	ft_bzero(fdf, sizeof(t_fdf));
	init_map(&(fdf->map), file_data);
	init_transform(&(fdf->transform));
}

void	init_mlx(t_fdf *fdf, char *file_name)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		exit_msg("[ERROR] mlx didn't created\n");
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr,
			SCREEN_WIDTH, SCREEN_HEIGHT, file_name);
	if (!fdf->win_ptr)
		exit_msg("[ERROR] window didn't created\n");
	mlx_key_hook(fdf->win_ptr, &key_hook, fdf);
	mlx_mouse_hook(fdf->win_ptr, &mouse_hook, fdf);
	mlx_loop_hook(fdf->mlx_ptr, &loop_hook, fdf);
	mlx_hook(fdf->win_ptr, EVENT_CLOSE, 0, &close_hook, fdf);
}
