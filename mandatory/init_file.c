/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 23:00:41 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 22:09:05 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"
#include "utils.h"

int		get_next_line(int fd, char **line_ptr);

int		parse_next_line(char ****words_ptr, int fd);
int		is_valid_format(char *word);

#include <stdio.h>
char	***read_file(char *filename)
{
	int		fd;
	int		eol_flag;
	char	***words;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit_msg("file open error\n");
	eol_flag = 0;
	words = (char ***)ft_calloc(1, sizeof(char **));
	if (!words)
		exit_msg("malloc error\n");
	while (!eol_flag)
	{
		eol_flag = parse_next_line(&words, fd);
		printf("line %lu read\n", ft_arrlen((void **)words));
		if (eol_flag == 0)
			break ;
	}
	close(fd);
	return (words);
}

int	parse_next_line(char ****words_ptr, int fd)
{
	char	*line;
	size_t	line_cnt;
	int		gnl_status;

	gnl_status = get_next_line(fd, &line);
	if (gnl_status == -1)
		exit_msg("malloc error\n");
	else if (gnl_status == -2)
		exit_msg("file read error\n");
	if (ft_strchr(line, '\n'))
		*ft_strchr(line, '\n') = '\0';
	line_cnt = ft_arrlen((void **)*words_ptr);
	*words_ptr = (char ***)ft_realloc(*words_ptr,
			(line_cnt + 1) * sizeof(char **),
			(line_cnt + 2) * sizeof(char **));
	if (!*words_ptr)
		exit_msg("malloc error\n");
	(*words_ptr)[line_cnt] = ft_split(line, ' ');
	free(line);
	if (!*words_ptr[line_cnt])
		exit_msg("malloc error\n");
	(*words_ptr)[line_cnt + 1] = NULL;
	if (gnl_status == 0)
		return (1);
	else
		return (0);
}

int	is_valid(char ***words)
{
	size_t	width;
	size_t	i;
	size_t	j;

	width = ft_arrlen((void **)words[0]);
	i = 0;
	while (words[i])
	{
		if (ft_arrlen((void **)words[i]) != width)
		{
			write(1, "[Invalid format] FdF is not rectangle\n", 38);
			return (0);
		}
		j = 0;
		while (j < width)
		{
			if (!is_valid_format(words[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_valid_format(char *word)
{
	if (*word == '+' || *word == '-')
		word++;
	while (ft_isdigit(*word))
		word++;
	if (*word == ',')
	{
		if (ft_strncmp(++word, "0x", 2))
		{
			write(1, "[Invalid format] Color is not valid format\n", 55);
			return (0);
		}
		word += 2;
		while (ft_isdigit(*word)
			|| ('A' <= *word && *word <= 'F')
			|| ('a' <= *word && *word <= 'f'))
			word++;
	}
	if (*word)
	{
		write(1, "[Invalid format] Altitude is not valid format\n", 55);
		return (0);
	}
	else
		return (1);
}
