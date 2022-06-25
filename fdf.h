/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:54:05 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/25 20:22:55 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define COS30 0.86602540
# define SIN30 0.5

# define PADDING 0.2

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_pixel
{
	int	x;
	int	y;
	int	color;
}	t_pixel;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_pixel	origin;
	int		**edges;
	t_pixel	**dots;
}

#endif
