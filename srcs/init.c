/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:47:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 20:06:04 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <mlx.h>

#include "libft.h"
#include "fdf.h"
#include "config.h"
#include "utils.h"

void	init_file(char ****file_data, char *file_name);
void	init_fdf(t_fdf *fdf, char ***file_data);
void	init_mlx(t_mlx *mlx);

void	init(t_mlx *mlx, t_fdf *fdf, char *file_name)
{
	char	***data;

	init_file(&data, file_name);
	write(1, "[success] read file\n", 20);
	init_fdf(fdf, data);
	write(1, "[success] init fdf\n", 19);
	free_darr(data);
	init_mlx(mlx);
	write(1, "[success] init mlx\n", 19);
}

void	init_mlx(t_mlx *mlx)
{
	ft_bzero(mlx, sizeof(t_mlx));
	mlx -> mlx_ptr = mlx_init();
	if (!(mlx -> mlx_ptr))
		exit_msg(-1, "mlx didn't generated\n");
	mlx -> win_ptr = mlx_new_window(
			mlx -> mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!(mlx -> win_ptr))
		exit_msg(-1, "mlx window didn't generated\n");
}
