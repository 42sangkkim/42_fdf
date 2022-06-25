/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 20:37:52 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

char	*read_whole_file(int fd);
char	*append_buffer(char *old_content, char *buffer, ssize_t read_len);

char	*read_file(char *filename)
{
	int		fd;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
		// file open error
	content = read_whole_file(fd);
	close(fd);
	if (!content)
		// malloc error
	return (content);
}

char	*read_whole_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	char	*tmp;
	ssize_t	read_len;

	content = ft_strdup("");
	while (content)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len > 0)
			content = append_buffer(content, buffer, read_len);
		else if (read_len < 0)
		{
			free(content);
			close (fd);
			// read error
		}
		else
			break ;
	}
	return (content);
}

char	*append_buffer(char *old_content, char *buffer, ssize_t read_len)
{
	char	*new_content;

	buffer[read_len] = '\0';
	new_content = ft_strjoin(old_content, buffer);
	free(old_content);
	return (new_content);
}

char	***parse_content(char *content)
{
	char	**lines;
	char	***words;

	lines = parse_nl(content);
	words = ft_calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (!words)
		// err
	i = 0;
	while (lines[i])
	{
		words[i] = ft_split(lines[i], ' ');
		if (words[i])
		{
			while(i--)
				free_arr(words[i]);
			free(words);
			free(*lines);
			free(lines);
		}
		i++;
	}
	free(*lines);
	free(lines);
	return (words);
}


char	**parse_nl(char *content)
{
	char	**lines;

	lines = ft_calloc(count_nl(content) + 2, sizeof(char *));
	if (!lines)
		// malloc error
	lines[0] = content;
	i = 1;
	while (1)
	{
		lines[i] = ft_strchr(lines[i - 1], '\n');
		if (lines[i] == NULL)
			break ;
		*(lines[i]++) = '\0';
		i++;
	}
	return (lines);
}
