/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/30 14:01:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "fdf.h"
#include "utils.h"
#include "config.h"

void	parse_coordinate(t_fdf *fdf, char ***file_data);
void	get_z_range(double *range, t_point **volume,
			size_t height, size_t width);
void	init_colors(t_point **volume, size_t height, size_t width);
t_color	get_color(const char *s);

void	init_fdf(t_fdf *fdf, char ***data)
{
	ft_bzero(fdf, sizeof(t_fdf));
	fdf -> height = ft_arrlen(data);
	fdf -> width = ft_arrlen(data[0]);
	fdf -> tr.altitude = 1.;
	fdf -> tr.zoom = 1.;
	fdf -> volume = (t_point **)malloc_array(
			fdf -> height, fdf -> width, sizeof(t_point));
	fdf -> screen = (t_point **)malloc_array(
			fdf -> height, fdf -> width, sizeof(t_point));
	if (!(fdf -> volume) || !(fdf -> screen))
		exit_msg(-1, "malloc error\n");
	parse_coordinate(fdf, data);
	init_colors(fdf -> volume, fdf -> height, fdf -> width);
}

void	parse_coordinate(t_fdf *fdf, char ***file_data)
{
	size_t	i;
	size_t	j;
	int		ox;
	int		oy;

	ox = fdf -> height / 2;
	oy = fdf -> width / 2;
	i = 0;
	while (i < fdf -> height)
	{
		j = 0;
		while (j < fdf -> width)
		{
			fdf -> volume[i][j].x = (double)((int)i - ox);
			fdf -> volume[i][j].y = (double)((int)j - oy);
			fdf -> volume[i][j].z = (double)ft_atoi(file_data[i][j]);
			if (ft_strchr(file_data[i][j], 'x'))
				fdf -> volume[i][j].color
					= get_color(ft_strchr(file_data[i][j], 'x') + 1);
			else
				fdf -> volume[i][j].color.value = MIN_COLOR;
			j++;
		}
		i++;
	}
}

void	get_z_range(double *range, t_point **volume,
		size_t height, size_t width)
{
	size_t	i;
	size_t	j;

	range[0] = volume[0][0].z;
	range[1] = volume[0][0].z;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (range[0] > volume[i][j].z)
				range[0] = volume[i][j].z;
			if (range[1] < volume[i][j].z)
				range[1] = volume[i][j].z;
			j++;
		}
		i++;
	}
}

void	init_colors(t_point **volume, size_t height, size_t width)
{
	size_t	i;
	size_t	j;
	double	z_range[2];
	double	diff_z;

	get_z_range((double *)z_range, volume, height, width);
	if (z_range[0] == z_range[1])
		return ;
	diff_z = z_range[1] - z_range[0];
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (volume[i][j].color.value & 0xFF000000)
				volume[i][j].color = color_picker(
						(t_color)MIN_COLOR, (t_color)MAX_COLOR,
						(volume[i][j].z - z_range[0]) / diff_z);
			j++;
		}
		i++;
	}
}

t_color	get_color(const char *s)
{
	t_color	color;

	color.value = 0;
	while (*s)
	{
		color.value *= 16;
		if (ft_isdigit(*s))
			color.value += *s - '0';
		else if ('A' <= *s && *s <= 'F')
			color.value += *s - 'A' + 10;
		else if ('a' <= *s && *s <= 'f')
			color.value += *s - 'a' + 10;
		else
			break ;
		s++;
	}
	return (color);
}
