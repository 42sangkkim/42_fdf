/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:04:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 16:46:01 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "utils.h"
#include "fdf.h"

void	**malloc_array(size_t height, size_t width, size_t size)
{
	size_t	i;
	void	**arr;

	arr = malloc((height + 1) * sizeof(void *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		arr[i] = malloc(width * size);
		if (!arr[i])
		{
			while (i--)
				free(arr[i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_color	color_picker(t_color c1, t_color c2, double ratio)
{
	t_color	color;
	double	r_ratio;

	r_ratio = 1 - ratio;
	color.rgb.r = (double)c1.rgb.r * r_ratio + (double)(c2.rgb.r * ratio);
	color.rgb.g = (double)c1.rgb.g * r_ratio + (double)(c2.rgb.g * ratio);
	color.rgb.b = (double)c1.rgb.b * r_ratio + (double)(c2.rgb.b * ratio);
	return (color);
}
