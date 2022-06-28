/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:01:10 by sangkkim          #+#    #+#             */
/*   Updated: 2022/06/27 14:09:15 by sangkkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

size_t	ft_arrlen(void *arr);
void	free_str_arr(char **arr);
void	free_str_darr(char ***darr);
size_t	ft_strcnt(const char *s, int c);

#endif
