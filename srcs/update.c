/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:12:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 02:31:56 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>

#include <fdf.h>
#include <utils.h>

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

#include <stdio.h>
int	key_hook(int keycode, void *params)
{
	void	**parameters;
	t_mlx	*mlx;

	printf("key : %d\n", keycode);
	if (keycode == 53)
	{
		parameters = params;
		mlx = (t_mlx *)parameters[0];
		mlx_destroy_window(mlx -> mlx_ptr, mlx -> win_ptr);
		exit_msg(0, "exit!");
	}
	return (1);
}