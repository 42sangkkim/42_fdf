/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 01:02:11 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <libft.h>

#include <fdf.h>
#include <utils.h>
#include <config.h>
void	parse_coordinate(t_fdf *fdf, char ***file_data)
{
	size_t	i;
	size_t	j;
	int		ox;
	int		oy;
	t_point	point;

	ox = fdf -> height / 2;
	oy = fdf -> width / 2;
	i = 0;
	while (i < fdf -> height)
	{
		j = 0;
		while (j < fdf -> width)
		{
			point.x = (double)((int)i - ox);
			point.y = (double)((int)j - oy);
			point.z = (double)ft_atoi(file_data[i][j]);
			point.color = MIN_COLOR;
			fdf -> volume[i][j] = point;
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
	diff_z = z_range[1] - z_range[0];
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			volume[i][j].color = color_picker(MIN_COLOR, MAX_COLOR,
					(volume[i][j].z - z_range[0] / diff_z));
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
		if (!words[i])
			exit_msg(-1, "malloc error\n");
		i++;
	}
	free_arr(lines);
	return (words);
}
