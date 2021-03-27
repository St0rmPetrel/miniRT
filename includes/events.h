/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:45:38 by serma             #+#    #+#             */
/*   Updated: 2021/02/01 17:07:47 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "draw_data.h"

void	change_camera(t_draw_data *data);
void	camera_move(t_draw_data *data, int coordinate, double factor);
void	camera_rotation(t_draw_data *data, int coordinate, double factor);
void	change_caps(t_draw_data *data);

#endif
