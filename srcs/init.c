/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 00:50:21 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 15:34:29 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	init(t_map *map, t_mlx mlx, int fd)
{
	char	*file_data;
	char	***words;

	file_data = read_file(fd);
	if (!file_data)
		exit(-1);
	*map = parse_to_intmap(content);
	words = ft_mega_split(file_data);
	*map = parse_data(words);
	if (!(map -> map))
		exit(-1);
	*mlx = init_mlx(map);
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

t_map	parse_data(char ***words)
{
	t_map	map;
	int		*arr;

	map.height = ft_arrlen(words);
	map.width = ft_arrlen(*words);
	map.map = malloc(map.height * sizeof(int *));
	arr = malloc(map.height * map.width * sizeof(int));
	if (!map.map || !arr)
	{
		free(map.map);
		free(arr);
		map.map = NULL;
		return (map);
	}
	x = 0;
	while (x < map.height)
	{
		map.map[x] = arr;
		y = 0;
		while (y < map.width)
		{
			*arr++ = ft_atoi(words[x][y]);
			y++;
		}
		x++;
	}
	return (map);
}
