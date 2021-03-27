/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_digit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:21:08 by serma             #+#    #+#             */
/*   Updated: 2021/01/16 16:04:24 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_TO_DIGIT_H
# define STR_TO_DIGIT_H

# include "vectormath.h"
# include "colors.h"

double		ft_strtod(const char *str);
t_vector	ft_strtovec(const char *str);
t_color		ft_strtocolor(const char *str);
int			len_of_array(void **arr);

#endif
