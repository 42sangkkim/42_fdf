/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:16:54 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 21:41:39 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_arrlen(void **arr)
{
	size_t	len;

	len = 0;
	while (*arr++)
		len++;
	return (len);
}

void	free_darr_str(char ***p)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			free(p[i][j]);
			j++;
		}
		free(p[i]);
		i++;
	}
	free(p);
}

size_t	ft_strcnt(const char *s, int c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == (char )c)
			cnt++;
		s++;
	}
	if (*s == (char)c)
		cnt++;
	return (cnt);
}
