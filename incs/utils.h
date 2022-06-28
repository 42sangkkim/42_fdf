/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/29 03:29:45 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fdf.h>

// srcs/util1.c
size_t	ft_arrlen(void *arr);
void	free_arr(char **arr);
void	free_darr(char ***darr);
size_t	ft_strcnt(const char *s, int c);
void	exit_msg(int code, char *msg);

// srcs/util2.c
void	**malloc_array(size_t height, size_t width, size_t size);
t_color	color_picker(t_color c1, t_color c2, double ratio);

#endif
