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

	lines = ft_calloc(count_nl(content) + 2, sizeof(char *));
	if (!lines)
		// malloc error
	lines[0] = content;
	i = 0;
	while (lines[i]
	lines[1]
