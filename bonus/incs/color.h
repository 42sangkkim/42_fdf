/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:55:23 by sangkkim          #+#    #+#             */
/*   Updated: 2022/07/04 23:56:49 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef union u_color
{
	int	value;
	struct s_rgb
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
	}	rgb;
}	t_color;

#endif
