/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 17:43:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 18:12:07 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "fdf_bonus.h"
#include "utils_bonus.h"

void	init_map(t_map *map);
void	parse_altitude(t_map *map, char ***words);
void	parse_color(t_map *map, char ***words);

void	parse_map(t_map *map, char ***words)
{
	map->height = ft_arrlen((void **)words);
	map->width = ft_arrlen((void **)words[0]);
	init_map(map);
	parse_altitude(map, words);
	parse_color(map, words);
}

void	init_map(t_map *map)
{
	size_t	i;
	size_t	j;

	map->data = (t_pixel **)malloc_array(
			map->height, map->width, sizeof(t_pixel));
	if (!map->data)
		exit_msg("malloc error\n");
	map->max_edge.x = (double)(map->height - 1) / 2;
	map->max_edge.y = (double)(map->width - 1) / 2;
	map->min_edge.x = -(map->max_edge.x);
	map->min_edge.y = -(map->max_edge.y);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->data[i][j].dim_3.x = (double)i + map->min_edge.x;
			map->data[i][j].dim_3.y = (double)j + map->min_edge.y;
			j++;
		}
		i++;
	}
}

void	parse_altitude(t_map *map, char ***words)
{
	size_t	i;
	size_t	j;

	map->min_edge.z = (double)ft_atoi(words[0][0]);
	map->max_edge.z = map->min_edge.z;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			map->data[i][j].dim_3.z = (double)ft_atoi(words[i][j]);
			if (map->min_edge.z > map->data[i][j].dim_3.z)
				map->min_edge.z = map->data[i][j].dim_3.z;
			if (map->max_edge.z < map->data[i][j].dim_3.z)
				map->max_edge.z = map->data[i][j].dim_3.z;
			j++;
		}
		i++;
	}
}

void	parse_color(t_map *map, char ***words)
{
	size_t	i;
	size_t	j;
	double	z_range;

	z_range = map->max_edge.z - map->min_edge.z;
	if (z_range == 0)
		z_range = 1;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (ft_strchr(words[i][j], ','))
				map->data[i][j].color.value
					= ft_atoi_hex(ft_strchr(words[i][j], 'x') + 1);
			else
				map->data[i][j].color = mix_color(
						(t_color)MIN_COLOR, (t_color)MAX_COLOR,
						(map->data[i][j].dim_3.z - map->min_edge.z) / z_range);
			j++;
		}
		i++;
	}
}
