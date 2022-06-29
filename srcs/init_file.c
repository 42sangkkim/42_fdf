/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:21:56 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 20:08:41 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft.h"
#include "utils.h"
#include "config.h"

char	*read_file(int fd);
char	***split_all(char *raw_data);
void	check_data(char ***data);
void	check_format(char *data);

void	init_file(char ****data, const char *file_name)
{
	int		fd;
	char	*raw_data;

	fd = open(file_name, O_RDONLY);
	if (fd < 3)
		exit_msg(-1, "file open error\n");
	raw_data = read_file(fd);
	close(fd);
	*data = split_all(raw_data);
	free(raw_data);
	check_data(*data);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp_data;
	char	*raw_data;
	ssize_t	read_len;
	size_t	file_len;

	raw_data = ft_strdup("");
	file_len = 1;
	while (raw_data)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len > 0)
		{
			buffer[read_len] = '\0';
			tmp_data = ft_strjoin(raw_data, buffer);
			free(raw_data);
			raw_data = tmp_data;
		}
		else if (read_len < 0)
			exit_msg(-1, "read_error\n");
		else
			return (raw_data);
	}
	exit_msg(-1, "malloc_error\n");
	return (NULL);
}

char	***split_all(char *raw_data)
{
	char	***splited_data;
	char	**lines;
	size_t	i;

	lines = ft_split(raw_data, '\n');
	if (!lines)
		exit_msg(-1, "malloc_error\n");
	splited_data = calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (!splited_data)
		exit_msg(-1, "malloc_error\n");
	i = 0;
	while (lines[i])
	{
		splited_data[i] = ft_split(lines[i], ' ');
		if (!splited_data[i])
			exit_msg(-1, "malloc_error\n");
		i++;
	}
	free_arr(lines);
	return (splited_data);
}

void	check_data(char ***data)
{
	size_t	width;
	size_t	i;

	width = ft_arrlen(*data);
	while (*data)
	{
		if (ft_arrlen(*data) != width)
			exit_msg(0, "map is not rect\n");
		i = 0;
		while (i < width)
			check_format((*data)[i++]);
		data++;
	}
}

void	check_format(char *data)
{
	char	**arr;
	char	*str;

	arr = ft_split(data, ',');
	str = arr[0];
	while (*str)
		if (!ft_isdigit(*str++))
			exit_msg(0, "Altitude must in decimal\n");
	str = arr[1];
	if (!str)
		return ;
	if (ft_strncmp("0x", str, 2))
		exit_msg(0, "Color must in hexadecimal\n");
	str += 2;
	while (*str)
	{
		if (!ft_isdigit(*str)
			&& (*str < 'A' || *str > 'F')
			&& (*str < 'a' || *str > 'f'))
			exit_msg(0, "Invalid hexadecimal format\n");
		str++;
	}
	free_arr(arr);
}
