/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:09:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/21 16:13:27 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	***parse_content(char *content)
{
	char	**lines;
	char	***words;

	lines = parse_nl(content);
	words = ft_calloc(ft_arrlen(lines) + 1, sizeof(char **));
	if (!words)
		// err
	i = 0;
	while (lines[i])
	{
		words[i] = ft_split(lines[i], ' ');
		if (words[i])
		{
			while(i--)
				free_arr(words[i]);
			free(words);
			free(*lines);
			free(lines);
		}
		i++;
	}
	free(*lines);
	free(lines);
	return (words);
}


char	**parse_nl(char *content)
{
	char	**lines;

	lines = ft_calloc(count_nl(content) + 2, sizeof(char *));
	if (!lines)
		// malloc error
	lines[0] = content;
	i = 1;
	while (1)
	{
		lines[i] = ft_strchr(lines[i - 1], '\n');
		if (lines[i] == NULL)
			break ;
		*(lines[i]++) = '\0';
		i++;
	}
	return (lines);
}
