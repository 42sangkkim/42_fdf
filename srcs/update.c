/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:12:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 01:45:54 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <fdf.h>

void	update_fdf(t_fdf *fdf);

void	update(t_fdf *fdf)
{
	static t_transform	tr;

	if (ft_memcmp(&tr, &(fdf -> tr), sizeof(t_transform)))
	{
		tr = fdf -> tr;
		update_fdf(fdf);
	}
}