/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:11:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 23:21:52 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "libft.h"

#define BUFFER_SIZE 100

char	*append_buffer(char *mem, char *buf, ssize_t buf_len);
char	*pop_line(char **mem_ptr);

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*tmp;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_len;

	if (!memory)
		memory = ft_strdup("");
	while (memory && !ft_strchr(memory, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == 0)
			break ;
		memory = append_buffer(memory, buffer, read_len);
	}
	if (!memory)
		return (NULL);
	tmp = pop_line(&memory);
	return (tmp);
}

char	*append_buffer(char *mem, char *buf, ssize_t buf_len)
{
	char	*new_mem;

	if (buf_len < 0)
	{
		free(mem);
		return (NULL);
	}
	else
	{
		buf[buf_len] = '\0';
		new_mem = ft_strjoin(mem, buf);
		free(mem);
		return (new_mem);
	}
}

char	*pop_line(char **mem_ptr)
{
	char	*line;
	char	*nl_ptr;

	if (!**mem_ptr)
	{
		free(*mem_ptr);
		return (NULL);
	}
	line = *mem_ptr;
	nl_ptr = ft_strchr(line, '\n');
	if (!nl_ptr || !*nl_ptr)
		*mem_ptr = NULL;
	else
	{
		*mem_ptr = ft_strdup(nl_ptr + 1);
		if (!*mem_ptr)
		{
			free(line);
			return (NULL);
		}
		*(nl_ptr + 1) = '\0';
	}
	return (line);
}
