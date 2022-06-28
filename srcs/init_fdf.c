/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:19:44 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 16:54:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../incs/fdf.h"
#include "../incs/config.h"
#include "../libft/libft.h"

void	parse_volume(t_fdf *fdf, char ***data);
void	update_z_range(double *max, double *min, double value);
void	set_color(t_point **volume, size_t height, size_t width
		, double z_min, double z_max);

// draw_fdf.c
int		get_gradation(int c1, int c2, double ratio);

char	***

t_fdf	*init_fdf(char ***data)
{
	t_fdf	*fdf;
	size_t	width;
	size_t	height;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (NULL);
	width = ft_arrlen(data[0]);
	height = ft_arrlen(data);
	fdf -> volume = (t_point **)malloc_array(height, width, sizeof(t_point));
	fdf -> screen = (t_point **)malloc_array(height, width, sizeof(t_point));
	if (!(fdf -> volume) || !(fdf -> screen))
	{
		free_arr(fdf -> volume);
		free_arr(fdf -> screen);
		free(fdf);
		return (NULL);
	}
	parse_volume(fdf, data);
	return (fdf);
}

void	parse_volume(t_fdf *fdf, char ***data)
{
	size_t	i;
	size_t	j;
	double	z_max;
	double	z_min;
	t_point	point;

	z_max = (double)ft_atoi(data[0][0]);
	z_min = z_max;
	height = fdf -> height;
	i = 0;
	while (i < (fdf -> height))
	{
		j = 0;
		while (j < (fdf -> width))
		{
			point.x = (double)(i - (fdf -> height) / 2);
			point.y = (double)(j - (fdf -> width) / 2)
			point.z = (double)ft_atoi(data[i][j]);
			update_z_range(&z_max, &z_min, point.z);
			fdf -> volume[i][j] = point;
			j++;
		}
		i++;
	}
	set_color(fdf -> volume, fdf -> height, fdf -> width, z_man, z_min);
}

void	update_z_range(double *max, double *min, double value)
{
	if (*max < value)
		*max = value;
	if (*min > value)
		*min = value;
}

void	set_color(t_point **volume, size_t height, size_t width
		, double z_min, double z_max)
{
	size_t	i;
	size_t	j;
	double	range;

	range = z_max - z_min;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			volume[i][j].color = 
				get_gradation(MIN_COLOR, MAX_COLOR, range / (volume[i][j] - z_min);
			j++;
		}
		i++;
	}
}
