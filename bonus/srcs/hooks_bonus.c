/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:22:42 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/05 18:56:42 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "mlx.h"
#include "fdf_bonus.h"
#include "libft.h"

#define KEY_A				0
#define KEY_S				1
#define KEY_Z				6
#define KEY_X				7
#define KEY_Q				12
#define KEY_W				13
#define KEY_E				14
#define KEY_R				15
#define KEY_1				18
#define KEY_2				19
#define KEY_PLUS			24
#define KEY_MINUS			27
#define KEY_ESC				53
#define KEY_ARROW_UP		126
#define KEY_ARROW_LEFT		123
#define KEY_ARROW_DOWN		125
#define KEY_ARROW_RIGHT		124


#define MOUSE_LEFT			1
#define MOUSE_RIGHT			2
#define MOUSE_MIDDLE		3
#define MOUSE_WHEEL_UP		4
#define MOUSE_WHEEL_DOWN	5

void	update(t_fdf *fdf);
void	draw(t_fdf *fdf);

int		key_hook_2(int keycode, t_fdf *fdf);

int	key_hook(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr);
		write(1, "good bye!\n", 10);
		exit(0);
	}
	else if (keycode == KEY_ARROW_UP)
		fdf->transform.oy += D_TRANSLATE;
	else if (keycode == KEY_ARROW_DOWN)
		fdf->transform.oy -= D_TRANSLATE;
	else if (keycode == KEY_ARROW_LEFT) 
		fdf->transform.ox += D_TRANSLATE;
	else if (keycode == KEY_ARROW_RIGHT)
		fdf->transform.ox -= D_TRANSLATE;
	else if (keycode == KEY_PLUS)
		fdf->transform.z_gain *= D_GAIN;
	else if (keycode == KEY_MINUS)
		fdf->transform.z_gain *= 1. / D_GAIN;
	else
		key_hook_2(keycode, fdf);
	return (keycode);
}

int	key_hook_2(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Q)
		fdf->transform.quaternion.x += D_ROTATE;
	else if (keycode == KEY_W)
		fdf->transform.quaternion.x -= D_ROTATE;
	else if (keycode == KEY_A)
		fdf->transform.quaternion.y += D_ROTATE;
	else if (keycode == KEY_S)
		fdf->transform.quaternion.y -= D_ROTATE;
	else if (keycode == KEY_Z)
		fdf->transform.quaternion.z += D_ROTATE;
	else if (keycode == KEY_X)
		fdf->transform.quaternion.z -= D_ROTATE;
	else if (keycode == KEY_1)
		fdf->transform.mode = PERALLEL;
	else if (keycode == KEY_2)
		fdf->transform.mode = ONE_POINT;
	else if (keycode == KEY_E)
		fdf->transform.fov += D_FOV;
	else if (keycode == KEY_R)
		fdf->transform.fov -= D_FOV;
	return (keycode);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == MOUSE_WHEEL_UP)
		fdf->transform.zoom *= 1. / D_ZOOM;
	else if (button == MOUSE_WHEEL_DOWN)
		fdf->transform.zoom *= D_ZOOM;
	return (button);
}

int	loop_hook(void *param)
{
	static t_transform	prev_tr;
	t_fdf				*fdf;

	fdf = (t_fdf *)param;
	if (ft_memcmp(&(fdf->transform), &prev_tr, sizeof(t_transform)))
	{
		prev_tr = fdf->transform;
		update(fdf);
		draw(fdf);
		return (1);
	}
	return (0);
}

int	close_hook(void *param)
{
	write(1, "good bye!\n", 10);
	exit(0);
}
