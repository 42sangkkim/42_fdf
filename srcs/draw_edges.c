/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:06:25 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/26 19:14:59 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	draw_edges(t_fdf fdf, t_mlx)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < fdf.height)
	{
		j = 0;
		while (j < fdf.width)
		{
			if (i)
				draw_line(fdf.plane[i - 1][j], fdf.plane[i][j], mlx);
			if (j)
				draw_line(fdf.plane[i][j - 1], fdf.plane[i][j], mlx);
			j++;
		}
		i++;
	}
}

void	draw_line(t_point p1, t_point p2, t_mlx mlx)
{
	
