/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_guide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 03:47:51 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 03:49:57 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include <fdf.h>
#include <config.h>

void	draw_guide(t_mlx *mlx)
{
	mlx_string_put(mlx -> mlx_ptr, mlx -> win_ptr, 0, 0, 0xFFFFFF, "string");
}