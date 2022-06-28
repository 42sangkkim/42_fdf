/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:16:54 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/27 14:07:51 by sangkkim         ###   ########.fr       */
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

void	free_str_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_str_darr(char ***darr)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (darr[i])
		free_str_arr(darr[i++]);
	free(darr);
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
