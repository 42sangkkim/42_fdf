/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_guide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:47:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 12:27:24 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include <fdf.h>
#include <config.h>

void	draw_guide(t_mlx *mlx)
{
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 0, 0xFFFFFF, "W A S D : move");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 20, 0xFFFFFF, "Q E    : rotate");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 40, 0xFFFFFF, "space  : auto rotate");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 60, 0xFFFFFF, "[ ]    : altitude");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 80, 0xFFFFFF, "- +    : zoom");
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 100, 0xFFFFFF, "esc    : exit");
}