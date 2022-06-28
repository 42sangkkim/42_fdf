/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:50:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/27 16:42:14 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../incs/utils.h"
#include "../libft/libft.h"
#define BUFFER_SIZE 100

void	free_str_arr(char **p);
void	free_str_darr(char ***p);
size_t	ft_strcnt(const char *s, int c);

char	*read_file(int fd);
char	***split_to_data(char *data);

char	***get_file_data(int argc, char **argv)
{
	int		fd;
	char	*content;
	char	***data;

	if (argc != 2)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (NULL);
	content = read_file(fd);
	close(fd);
	if (!content)
		return (NULL);
	data = split_to_data(content);
	free(content);
	if (!data)
		return (NULL);
	return (data);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*data;
	char	*tmp;
	ssize_t	read_len;

	data = ft_strdup("");
	while (data)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len > 0)
		{
			buffer[read_len] = '\0';
			tmp = ft_strjoin(data, buffer);
			free(data);
			data = tmp;
		}
		else if (read_len == 0)
			return (data);
		else
		{
			free(data);
			return (NULL);
		}
	}
	return (NULL);
}

char	***split_to_data(char *content)
{
	size_t	i;
	char	**lines;
	char	***words;

	lines = ft_split(content, '\n');
	if (!lines)
		return (NULL);
	words = ft_calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (words)
	{
		i = 0;
		while (lines[i])
		{
			words[i] = ft_split(lines[i], ' ');
			if (!words[i++])
			{
				free_str_darr(words);
				free_str_arr(lines);
				return (NULL);
			}
		}
	}
	free_str_arr(lines);
	return (words);
}

/*

char	***split_to_data(char *content)
{
	size_t	i;
	char	**lines;
	char	***words;

	lines = ft_split(content, '\n');
	if (!lines)
		return (NULL);
	words = ft_calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (!words)
	{
		free_str_arr(lines);
		return (NULL);
	}
	i = 0;
	while (lines[i])
	{
		words[i] = ft_split(lines[i], ' ');
		if (!words[i++])
		{
			free_str_arr(lines);
			free_str_darr(words);
			return (NULL);
		}
	}
	free_str_arr(lines);
	return (words);
}*/
