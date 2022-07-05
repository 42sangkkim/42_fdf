/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:22:42 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 12:17:09 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "mlx.h"
#include "fdf_bonus.h"

#define KEY_ESC 53

#define MOUSE_WHEEL_UP 4
#define MOUSE_WHEEL_DOWN 5

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
	static t_transform	prev_tr;
	t_fdf				*fdf;

	fdf = (t_fdf *)param;
	if (ft_memcpy(fdf->transform, prev_tr, sizeof(t_transform)))
	{
		prev_tr = fdf->transform;
		rotate(fdf);
		(fdf->projection)(fdf);
		translate(fdf);
		draw_fdf(fdf);
		return (1);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	if (button == MOUSE_WHEEL_UP)
	{
	}
	else if (button == MOUSE_WHEEL_DOWN)
	{
	}
	return (button);
}
