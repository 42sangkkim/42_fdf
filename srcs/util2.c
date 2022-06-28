/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:04:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 01:01:11 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <libft.h>
#include <utils.h>

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

int	color_picker(int c1, int c2, double ratio)
{
	int		color;
	double	r;
	double	g;
	double	b;

	r = ((double)(c1 & 0xFF0000 >> 16) * (1 - ratio))
		+ ((double)(c2 & 0xFF0000 >> 16) *  ratio);
	g = ((double)(c1 & 0x00FF00 >> 8) * (1 - ratio))
		+ ((double)(c2 & 0x00FF00 >> 8) * ratio);
	b = ((double)(c1 & 0x0000FF) * (1 - ratio))
		+ ((double)(c2 & 0x0000FF) * ratio);
	color = (((int)r & 0xFF) << 16) + (((int)g & 0xFF) << 8) + ((int)b & 0xFF);
	return (color);
}
