/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:43:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 21:46:44 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "fdf.h"
#include "utils.h"

void	init_map(t_fdf *fdf);
void	parse_altitude(t_fdf *fdf, char ***words);
void	parse_color(t_fdf *fdf, char ***words);

void	parse_map(t_fdf *fdf, char ***words)
{
	write(1, "\n\tinit ...\t", 11);
	fdf->height = ft_arrlen((void **)words);
	fdf->width = ft_arrlen((void **)words[0]);
	init_map(fdf);
	write(1, "OK\n", 3);
	write(1, "\taltitude ...\t", 14);
	parse_altitude(fdf, words);
	write(1, "OK\n", 3);
	write(1, "\tcolor ...\t", 11);
	parse_color(fdf, words);
	write(1, "OK\n", 3);
}

void	init_map(t_fdf *fdf)
{
	size_t	i;
	size_t	j;

	fdf->volume = (t_pixel **)malloc_array(
			fdf->height, fdf->width, sizeof(t_pixel));
	fdf->plane = (t_pixel **)malloc_array(
			fdf->height, fdf->width, sizeof(t_pixel));
	if (!fdf->volume || !fdf->plane)
		exit_msg("malloc error\n");
	fdf->max_edge.x = (double)fdf->height / 2;
	fdf->max_edge.y = (double)fdf->width / 2;
	fdf->min_edge.x = -(fdf->max_edge.x);
	fdf->min_edge.y = -(fdf->max_edge.y);
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			write(1, "?", 1);
			fdf->volume[i][j].x = (double)i - fdf->max_edge.x;
			fdf->volume[i][j].y = (double)j - fdf->max_edge.y;
			j++;
		}
		i++;
	}
}

void	parse_altitude(t_fdf *fdf, char ***words)
{
	size_t	i;
	size_t	j;

	fdf->min_edge.z = (double)ft_atoi(words[0][0]);
	fdf->max_edge.z = fdf->min_edge.z;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			fdf->volume[i][j].z = (double)ft_atoi(words[i][j]);
			if (fdf->min_edge.z > fdf->volume[i][j].z)
				fdf->min_edge.z = fdf->volume[i][j].z;
			if (fdf->max_edge.z < fdf->volume[i][j].z)
				fdf->max_edge.z = fdf->volume[i][j].z;
			j++;
		}
		i++;
	}
}

void	parse_color(t_fdf *fdf, char ***words)
{
	size_t	i;
	size_t	j;
	double	min_z;
	double	z_range;

	min_z = fdf->min_edge.z;
	z_range = fdf->max_edge.z - fdf->min_edge.z;
	i = 0;
	while (i < fdf->height)
	{
		j = 0;
		while (j < fdf->width)
		{
			if (ft_strchr(words[i][j], ','))
				fdf->volume[i][j].color.value
					= ft_atoi_hex(ft_strchr(words[i][j], 'x') + 1);
			else
				fdf->volume[i][j].color = mix_color(
						(t_color)MIN_COLOR, (t_color)MAX_COLOR,
						(fdf->volume[i][j].z - min_z) / z_range);
			j++;
		}
		i++;
	}
}
