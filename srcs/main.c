/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:55:08 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 21:52:12 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	***get_file_data(int argc, char **argv);
void	print_filedata(char ***file_data);

int	main(int argc, char **argv)
{
	char	***file_data;

	file_data = get_file_data(argc, argv);
	if (!file_data)
		return (-1);
	print_filedata(file_data);
	return (0);
}

#include <stdio.h>
void	print_filedata(char ***file_data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (file_data[i])
	{
		printf("%2d [%p]: ", (int)i, file_data[i]);
		j = 0;
		while (file_data[i][j])
		{
			printf("%s ", file_data[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
