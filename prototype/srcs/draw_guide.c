/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_guide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 00:51:57 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/07 00:56:27 by sangkkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"

void	draw_guide(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 0, GUIDE_COLOR,
			"Arrows : move");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 20, GUIDE_COLOR,
			"Scroll : zoom in/out");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 40, GUIDE_COLOR,
			"     1 : perallel projection");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 60, GUIDE_COLOR,
			"     2 : one point projection");
	mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 80, GUIDE_COLOR,
			"   + - : fov");
	if (fdf->transform.mode == PERALLEL)
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 100,
				GUIDE_COLOR, "mode : perallel projection");
	else
		mlx_string_put(fdf->mlx.mlx_ptr, fdf->mlx.win_ptr, 0, 100,
				GUIDE_COLOR, "mode : one point projection");
}

void	draw_status(t_fdf *fdf)