/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:47:53 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/06 20:55:32 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"

int	mouse_hook(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (button == BUTTON_SCROLL_UP)
		fdf->transform.zoom -= D_ZOOM;
	else if (button == BUTTON_SCROLL_DOWN)
		fdf->transform.zoom += D_ZOOM;
	return (button + x + y);
}

int	loop_hook(void *param)
{
	static t_transform	prev;
	static int			prev_mode;
	t_fdf				*fdf;

	fdf = (t_fdf *)param;
	if (fdf->projection != prev_mode
		|| ft_memcmp(&(fdf->transform), &prev, sizeof(t_transform)))
	{
		prev = fdf->transform;
		prev_mode = fdf->projection;
		update(fdf);
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw_fdf(fdf);
		draw_guide(fdf);
		draw_axis(fdf);
		return (1);
	}
	return (0);
}
