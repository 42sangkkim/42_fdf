/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 23:29:29 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <libft.h>

#include <fdf.h>
#include <utils.h>
#include <config.h>

// draw_fdf.c
int		get_gradation(int c1, int c2, double ratio);

void	parse_coordinate(t_fdf *fdf, char ***file_data)
{
	size_t	i;
	size_t	j;
	t_point	point;

	i = 0;
	while (i < fdf -> height)
	{
		j = 0;
		while (j < fdf -> width)
		{
			point.x = (double)(i - fdf -> height / 2);
			point.y = (double)(j - fdf -> width / 2);
			point.z = (double)ft_atoi(file_data[i][j]);
			point.color = MIN_COLOR;
			fdf -> volume[i][j] = point;
			j++;
		}
		i++;
	}
}

void	init_colors(t_point **volume, size_t height, size_t width)
{
	size_t	i;
	size_t	j;
	double	z_max;
	double	z_min;
	double	range;

	z_max = volume[0][0].z;
	z_min = z_max;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (z_max < volume[i][j].z)
				z_max = volume[i][j].z;
			if (z_min > volume[i][j].z)
				z_min = volume[i][j].z;
			j++;
		}
		i++;
	}
	range = z_max - z_min;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			volume[i][j].color = get_gradation(
					MIN_COLOR, MAX_COLOR, range / (volume[i][j].z - z_min));
			j++;
		}
		i++;
	}
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*data;
	char	*tmp;
	ssize_t	read_len;

	data = ft_strdup("");
	while (1)
	{
		if (!data)
			exit_msg(-1, "malloc error\n");
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len > 0)
		{
			buffer[read_len] = '\0';
			tmp = ft_strjoin(data, buffer);
			free(data);
			data = tmp;
		}
		else if (read_len == 0)
			break ;
		else
			exit_msg(-1, "read error\n");
	}
	return (data);
}

char	***split_to_data(char *content)
{
	size_t	i;
	char	**lines;
	char	***words;

	lines = ft_split(content, '\n');
	if (!lines)
		exit_msg(-1, "malloc error\n");
	words = ft_calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (!words)
		exit_msg(-1, "malloc error\n");
	i = 0;
	while (lines[i])
	{
		words[i] = ft_split(lines[i], ' ');
		if (!words[i++])
			exit_msg(-1, "malloc error\n");
	}
	free_arr(lines);
	return (words);
}
