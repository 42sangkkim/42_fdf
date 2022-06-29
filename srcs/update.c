/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 01:12:11 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 12:27:36 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>

#include <fdf.h>
#include <utils.h>
#include <config.h>

void	update_fdf(t_fdf *fdf);
void	draw_fdf(t_mlx *mlx, t_fdf *fdf);
void	draw_guide(t_mlx *mlx);

int	update(void *param)
{
	static t_transform	tr;
	t_mlx				*mlx;
	t_fdf				*fdf;

	mlx = (t_mlx *)((void **)param)[0];
	fdf = (t_fdf *)((void **)param)[1];
	if (fdf -> rotating)
		fdf -> tr.rotate ++;
	fdf -> tr.rotate %= ROTATE_RESOLUTION;
	if (ft_memcmp(&tr, &(fdf -> tr), sizeof(t_transform)))
	{
		tr = fdf -> tr;
		update_fdf(fdf);
		mlx_clear_window(mlx -> mlx_ptr, mlx -> win_ptr);
		draw_fdf(mlx, fdf);
		draw_guide(mlx);
	}
	return (0);
}

#include <stdio.h>
int	key_hook(int keycode, void *param)
{
	t_mlx	*mlx;
	t_fdf	*fdf;

	printf("key : %d\n", keycode);
	mlx = (t_mlx *)((void **)param)[0];
	fdf = (t_fdf *)((void **)param)[1];
	if (keycode == 53)
	{
		mlx_destroy_window(mlx -> mlx_ptr, mlx -> win_ptr);
		exit_msg(0, "exit!");
	}
	else if (keycode == 13) // W
		fdf -> tr.translate.y -= D_TRANSLATE;
	else if (keycode == 1) // S
		fdf -> tr.translate.y += D_TRANSLATE;
	else if (keycode == 0) // A
		fdf -> tr.translate.x -= D_TRANSLATE;
	else if (keycode == 2) // D
		fdf -> tr.translate.x += D_TRANSLATE;
	else if (keycode == 30) // ]
		fdf -> tr.altitude += 0.1;
	else if (keycode == 33) // [
		fdf -> tr.altitude -= 0.1;
	else if (keycode ==12) // Q
		fdf -> tr.rotate += D_ROTATE;
	else if (keycode == 14) // E
		fdf -> tr.rotate -= D_ROTATE;
	else if (keycode == 24) // -
		fdf -> tr.zoom *= 1.2;
	else if (keycode == 27) // +
		fdf -> tr.zoom *= 1. / 1.2;
	else if (keycode == 49) // sp
		fdf -> rotating = !(fdf -> rotating);
	return (keycode);
}
