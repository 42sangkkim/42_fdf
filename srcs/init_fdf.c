/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 17:47:46 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "fdf.h"

t_map	*get_map(char ***data)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map -> width = ft_arrlen(data[0]);
	map -> height = ft_arrlen(data);
	map -> data = ft_calloc((map -> height), sizeof(t_point *));
	if (!(map -> data))
	{
		free(map);
		return (NULL);
	}
	map -> data[0] = ft_calloc(
			(map -> width) * (map -> height), sizeof(t_point));
	if (!(map -> data[0]))
	{
		free(map -> data);
		free(map);
		return (NULL);
	}
	get_mapdata(map, data);
	free_darr_str(data);
	return (map);
}

void	get_mapdata(t_map *map, char ***data)
{
	size_t	i;
	size_t	j;
	size_t	width;
	size_t	hright;

	width = map -> width;
	height = map -> height;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			map -> data[i * width + j] = ft_atoi(data[i][j]);
			j++;
		}
		i++;
	}
}
