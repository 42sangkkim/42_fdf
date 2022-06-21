/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:00:50 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/21 16:05:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

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
