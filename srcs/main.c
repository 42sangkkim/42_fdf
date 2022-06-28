/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:55:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 23:10:48 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include <mlx.h>

#include <fdf.h>
#include <utils.h>

void	init(t_mlx *mlx, t_fdf *fdf, char *file_name);

void	print_filedata(char ***file_data);

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_fdf	fdf;

	if (argc != 2)
		exit_msg(-1, "fdf accept just one parameter");
	init(&mlx, &fdf, argv[1]);
	//print_filedata(file_data);
	return (0);
}

#include <stdio.h>
void	print_filedata(char ***file_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file_data[i])
	{
		printf("%2d [%p]: ", (int)i, file_data[i]);
		j = 0;
		while (file_data[i][j])
		{
			printf("%s ", file_data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
