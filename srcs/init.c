/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:47:35 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 23:27:02 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <mlx.h>
#include <libft.h>

#include <fdf.h>
#include <config.h>
#include <utils.h>

char	*read_file(int fd);
char	***split_to_data(char *content);
void	parse_coordinate(t_fdf *fdf, char ***file_data);
void	init_colors(t_point **volume, size_t height, size_t width);

char	***get_file_data(char *file_name);
void	init_fdf(t_fdf *fdf, char ***file_data);
void	init_mlx(t_mlx *mlx);

void	init(t_mlx *mlx, t_fdf *fdf, char *file_name)
{
	char	***file_data;

	file_data = get_file_data(file_name);
	init_fdf(fdf, file_data);
	free_darr(file_data);
	init_mlx(mlx);
}

char	***get_file_data(char *file_name)
{
	int		fd;
	char	*content;
	char	***file_data;

	fd = open(file_name, O_RDONLY);
	if (fd < 3)
		exit_msg(-1, "file open error\n");
	content = read_file(fd);
	close(fd);
	file_data = split_to_data(content);
	free(content);
	return (file_data);
}

void	init_fdf(t_fdf *fdf, char ***file_data)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf -> height = ft_arrlen(file_data);
	fdf -> width = ft_arrlen(file_data[0]);
	fdf -> volume = (t_point **)malloc_array(
			fdf -> height, fdf -> width, sizeof(t_point));
	if (!(fdf -> volume))
		exit_msg(-1, "malloc error\n");
	fdf -> screen = (t_point **)malloc_array(
			fdf -> height, fdf -> width, sizeof(t_point));
	if (!(fdf -> volume))
		exit_msg(-1, "malloc error\n");
	parse_coordinate(fdf, file_data);
	free_darr(file_data);
	init_colors(fdf -> volume, fdf -> height, fdf -> width);
}

void	init_mlx(t_mlx *mlx)
{
	ft_bzero(&mlx, sizeof(t_mlx));
	mlx -> mlx_ptr = mlx_init();
	if (!(mlx -> mlx_ptr))
		exit_msg(-1, "mlx didn't generated\n");
	mlx -> win_ptr
		= mlx_new_window(mlx -> mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
	if (!(mlx -> win_ptr))
		exit_msg(-1, "mlx window didn't generated\n");
}
