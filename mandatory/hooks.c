/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:22:42 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 20:22:35 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "mlx.h"
#include "fdf.h"

#define KEY_ESC 53

void	transform(t_fdf *fdf);
void	draw_fdf(t_fdf *fdf);

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		write(1, "goodbye!\n", 9);
		exit(0);
	}
	return (keycode);
}

int	loop_hook(void *param)
{
	static int	update_flag;
	t_fdf		*fdf;

	fdf = (t_fdf *)param;
	if (!update_flag)
	{
		update_flag = 1;
		transform(fdf);
		draw_fdf(fdf);
		return (1);
	}
	return (0);
}
