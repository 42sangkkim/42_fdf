/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:12:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 20:07:18 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>

#include "libft.h"
#include "fdf.h"
#include "utils.h"
#include "config.h"

void	update_fdf(t_fdf *fdf);
void	draw_fdf(t_mlx *mlx, t_fdf *fdf);
void	draw_guide(t_mlx *mlx);

void	update_transform(t_fdf *fdf, int keycode);

int	update(void *param)
{
	static t_transform	tr;
	t_mlx				*mlx;
	t_fdf				*fdf;

	mlx = (t_mlx *)((void **)param)[0];
	fdf = (t_fdf *)((void **)param)[1];
	if (fdf -> rotating)
		fdf -> tr.rotate ++;
	fdf -> tr.rotate = (fdf -> tr.rotate + (size_t)ROTATE_RESOLUTION)
		% (size_t)ROTATE_RESOLUTION;
	if (ft_memcmp(&tr, &(fdf -> tr), sizeof(t_transform)))
	{
		tr = fdf -> tr;
		update_fdf(fdf);
		write(1, "[success] update fdf\n", 21);
		mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
		write(1, "[DRAW   ] claer ", 16);
		draw_fdf(mlx, fdf);
		write(1, "fdf ", 4);
		draw_guide(mlx);
		write(1, "guide\n", 6);
	}
	return (0);
}

int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;
	t_fdf	*fdf;

	mlx = (t_mlx *)((void **)param)[0];
	fdf = (t_fdf *)((void **)param)[1];
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(mlx -> mlx_ptr, mlx -> win_ptr);
		exit_msg(0, "exit!");
	}
	else
		update_transform(fdf, keycode);
	return (keycode);
}

void	update_transform(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_W)
		fdf -> tr.translate.y -= D_TRANSLATE;
	else if (keycode == KEY_A)
		fdf -> tr.translate.x -= D_TRANSLATE;
	else if (keycode == KEY_S)
		fdf -> tr.translate.y += D_TRANSLATE;
	else if (keycode == KEY_D)
		fdf -> tr.translate.x += D_TRANSLATE;
	else if (keycode == KEY_Q)
		fdf -> tr.rotate -= D_ROTATE;
	else if (keycode == KEY_E)
		fdf -> tr.rotate += D_ROTATE;
	else if (keycode == KEY_R)
		fdf -> tr.altitude += D_ALTITUDE;
	else if (keycode == KEY_F)
		fdf -> tr.altitude -= D_ALTITUDE;
	else if (keycode == KEY_MINUS)
		fdf -> tr.zoom *= 1. / D_ZOOM;
	else if (keycode == KEY_PLUS)
		fdf -> tr.zoom *= D_ZOOM;
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_mlx	*mlx;
	t_fdf	*fdf;

	mlx = (t_mlx *)((void **)param)[0];
	fdf = (t_fdf *)((void **)param)[1];
	if (button == MOUSE_LEFT || button == MOUSE_RIGHT)
	{
		if (x == y)
			write(1, "awesome!\n", 9);
	}
	else if (button == MOUSE_MIDDLE)
		fdf -> rotating = !(fdf -> rotating);
	else if (button == MOUSE_WHEEL_UP)
		fdf -> tr.zoom *= 1.1;
	else if (button == MOUSE_WHEEL_DOWN)
		fdf -> tr.zoom *= 0.9;
	return (button);
}

void	draw_guide(t_mlx *mlx)
{
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 0, 0xFFFFFF,
		"W A S D : move");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 20, 0xFFFFFF,
		"Q E    : rotate");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 40, 0xFFFFFF,
		"R F    : altitude");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 60, 0xFFFFFF,
		"- +    : zoom");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 80, 0xFFFFFF,
		"Scroll : zoom");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 100, 0xFFFFFF,
		"esc    : exit");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 120, 0xFFFFFF,
		"WHEEL CLICK  : auto rotate");
}
