/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:47:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 16:54:03 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <mlx.h>
#include <libft.h>

#include <fdf.h>
#include <config.h>

void	init_fdf(t_fdf *fdf, char *file_name);
void	init_mlx(t_mlx *mlx);

void	init(t_mlx *mlx, t_fdf *fdf, char *file_name)
{
	init_mlx(mlx);
	init_fdf(fdf, file_name);
}

void	init_fdf(t_fdf *fdf, char *file_name)
{
	char	***file_data;

	file_data = get_file_data(file_name);
	parse_to_fdf(fdf, file_data);
	free_darr(file_data);
}


void	init_mlx(t_mlx *mlx)
{
	ft_bzero(&mlx, sizeof(t_mlx));
	mlx -> mlx_ptr = mlx_init();
	if (!(mlx.mlx_ptr))
		return ;
	mlx -> win_ptr = mlx_new_window(mlx -> mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}
