/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:20:20 by serma             #+#    #+#             */
/*   Updated: 2021/01/28 17:25:33 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "draw_data.h"

int		key_hook(int keycode, t_draw_data *data);
int		mouse_hook(int button, int x, int y, t_draw_data *data);
int		exit_and_free(t_draw_data *data);
int		key_push_hook(int keycode, t_draw_data *data);

#endif
