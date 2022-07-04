/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:56:32 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/02 17:15:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//#include "libft.h"
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s);

#define BUFFER_SIZE 100

// return value
//	 1 : A line has read
//	 0 : EOL has beed reached
//	-1 : Memory allocation error happened
//	-2 : File read error happened

int		get_next_line(int fd, char **line_ptr);
int		init(char **mem_ptr, int status);
int		append_buffer(char **mem_ptr, char *buffer, ssize_t buf_len);
int		pop_line(char **line_ptr, char **mem_ptr, int status);

int	get_next_line(int fd, char **line_ptr)
{
	static char	*memory;
	static int	status;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		read_len;

	status = init(&memory, status);
	while (status > 0 && memory && !ft_strchr(memory, '\n'))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		status = append_buffer(&memory, buffer, read_len);
	}
	if (status < 0)
	{
		free(memory);
		memory = NULL;
		return (status);
	}
	status = pop_line(line_ptr, &memory, status);
	return (status);
}

int	init(char **mem_ptr, int status)
{
	if (status < 0 || !*mem_ptr)
	{
		free(*mem_ptr);
		*mem_ptr = ft_strdup("");
		if (!*mem_ptr)
			return (-1);
		return (1);
	}
	return (status);
}

int	append_buffer(char **mem_ptr, char *buffer, ssize_t buf_len)
{
	char	*tmp;

	if (buf_len < 0)
		return (-2);
	else if (buf_len == 0)
		return (0);
	else
	{
		buffer[buf_len] = '\0';
		tmp = ft_strjoin(*mem_ptr, buffer);
		if (!tmp)
			return (-1);
		free(*mem_ptr);
		*mem_ptr = tmp;
		return (1);
	}
}

int	pop_line(char **line_ptr, char **mem_ptr, int status)
{
	char	*nl_ptr;

	*line_ptr = *mem_ptr;
	if (!*line_ptr)
		return (0);
	nl_ptr = ft_strchr(*line_ptr, '\n');
	if (!nl_ptr || !*(nl_ptr + 1))
		*mem_ptr = NULL;
	else
	{
		*mem_ptr = ft_strdup(nl_ptr + 1);
		if (!*mem_ptr)
		{
			free(*line_ptr);
			*line_ptr = NULL;
			return (-1);
		}
		*(nl_ptr + 1) = '\0';
	}
	return (status);
}
