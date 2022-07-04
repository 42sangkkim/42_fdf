/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 22:48:09 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 23:50:13 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include "libft.h"

#include "mlx.h"
#include "fdf.h"
#include "utils.h"

#define PADDING 0.2

int		key_hook(int keycode, void *param);
int		loop_hook(void *param);
char	***read_file(char *filename);
int		is_valid(char ***words);
void	parse_map(t_fdf *fdf, char ***words);

int		init_fdf(t_fdf *fdf, char *filename);
void	init_mlx(t_fdf *fdf, char *filename);

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	if (argc != 2)
	{
		write(1, "fdf accept one parameter which is filepath\n", 43);
		return (1);
	}
	if (init_fdf(&fdf, argv[1]) != 0)
		return (1);
	init_mlx(&fdf, argv[1]);
	mlx_loop(fdf.mlx.mlx_ptr);
	mlx_destroy_window(fdf.mlx.mlx_ptr, fdf.mlx.win_ptr);
	return (0);
}

int	init_fdf(t_fdf *fdf, char *filename)
{
	char	***words;

	write(1, "reading file... \t", 17);
	words = read_file(filename);
	write(1, "OK\n", 3);
	write(1, "checking file...\t", 18);
	if (!is_valid(words))
		return (-1);
	write(1, "OK\n", 3);
	ft_bzero(fdf, sizeof(t_fdf));
	write(1, "parsing file... \t", 17);
	parse_map(fdf, words);
	write(1, "OK\n", 3);
	free_double_array((void ***)words);
	return (0);
}

void	init_mlx(t_fdf *fdf, char *filename)
{
	fdf->mlx.screen_width
		= cos(M_PI / 6) * ((double)fdf->height + (double)fdf->width)
		* (1. + PADDING) * ZOOM;
	fdf->mlx.screen_height = (fmax(1., fdf->max_edge.z)
			+ fabs(fdf->min_edge.z)
			+ sin(M_PI / 6) * ((double)fdf->height + (double)fdf->width))
		* (1. + PADDING) * ZOOM;
	fdf->mlx.mlx_ptr = mlx_init();
	if (!fdf->mlx.mlx_ptr)
		exit_msg("mlx init error\n");
	fdf->mlx.win_ptr = mlx_new_window(fdf->mlx.mlx_ptr,
			fdf->mlx.screen_width, fdf->mlx.screen_height, filename);
	if (!fdf->mlx.win_ptr)
		exit_msg("mlx window open error\n");
	mlx_key_hook(fdf->mlx.win_ptr, &key_hook, fdf);
	mlx_loop_hook(fdf->mlx.mlx_ptr, &loop_hook, fdf);
}
