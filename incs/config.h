/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:20:49 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/28 23:22:39 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

// FILE READ
# define BUFFER_SIZE 100

// SCREEN

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define TITLE "sangkkim FdF"
# define MIN_COLOR 0xFFFFFF
# define MAX_COLOR 0xFF0000

// UPDATE

# define ROTATE_RESOLUTION 60.
# define ROTARE_DTheta (PI / 3)
# define TRANSLATE_DX 10.
# define TRANSLATE_DY 10.
# define ZOOM 0.1

#endif
