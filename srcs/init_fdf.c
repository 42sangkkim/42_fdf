/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 21:53:28 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

char	*read_whole_file(int fd);
char	*append_buffer(char *old_content, char *buffer, ssize_t read_len);

t_fdf	init_fdf(int argc, char **argv)
{
	t_fdf	fdf;
	int		fd;
	char	*content;

	if (argc != 2)
		exit(-1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		exit(-1);
	content = read_whole_file(fd);
	close(fd);
	if (!content)
		exit(-1);
	fdf.edges = parse_content(content);
	free(content);
	if (!(fdf.edges))
		exit(-1);
	measure_fdf(&fdf);
	return (fdf);
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
		{
			buffer[read_len] = '\0';
			tmp = ft_strjoin(content, buffer);
			free(content);
			content = tmp;
		}
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

char	***parse_content(char *content)
{
	size_t	line_cnt;
	size_t	word_cnt;
	char	**lines;
	char	***words;

	
	lines = parse_nl(content);
	words = ft_calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (!words)
		return (NULL);
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
