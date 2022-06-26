/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_to_int_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:34:41 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 16:32:03 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**parse_to_int_map(char *data)
{
	char	***words;
	int		**map;

	words = split_to_words(data);
	free(data);
	if (!words)
		return (NULL);
	map = iterate_atoi(words);
	i = 0;
	while (words[i])
		free_arr(words[i++]);
	free(words);
	if (!map)
		return (NULL);
	return (map);
}

char	***split_to_words(char *data)
{
	size_t	i;
	char	***words;
	char	*nl;

	cnt = ft_strcnt(data, '\n');
	words = ft_calloc(cnt + 1, sizeof(char **));
	i = 0;
	while (words)
	{
		nl = ft_strchr(data, '\n');
		if (nl)
			*nl = '\0';
		words[i] = ft_split(line_start);
		if (!words[i])
		{
			while (i--)
				free_arr(words[i]);
			free(words);
			return (NULL);
		}
		if (!nl)
			return (NULL);
		data = nl + 1;
		i++;
	}
	return (NULL);
}

size_t	ft_strcnt(const char *s, int c)
{
	size_t cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == (char)c)
			cnt++;
		s++;
	}
	if (*s == (char)c)
		cnt++;
	return (cnt);
}

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	**parse_to_int(char ***words)
{
	size_t	i;
	size_t	width;
	size_t	height;
	int		**map;

	width = ft_arrlen(words[0]);
	height = ft_arrlen(words);
	map = malloc((height + 1) * sizeof(int *));
	if (!map)
		return (NULL);
	map[0] = malloc((height * (width + 1)) * sizeof(int));
	i = 1;
	while (i < height)
	{
		map[i] = map[0] + (i * (width + 1));
		map[i][width] = NULL;
		i++;
	}
	map[i] = NULL;
	iterate_atoi(map, words, width, height);
	return (map);
}

void	iterate_atoi(int **map, char ***words, size_t width, size_t height)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			map[x][y] = ft_atoi(words[x][y]);
			x++;
		}
		map[x][y] = NULL;
		y++;
	}
}
	
