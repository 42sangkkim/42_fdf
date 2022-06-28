/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:04:46 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 23:08:48 by sangkkim         ###   ########.fr       */
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
