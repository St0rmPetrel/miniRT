/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_level_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serma <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:51:35 by serma             #+#    #+#             */
/*   Updated: 2021/01/25 16:34:28 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIGH_LEVEL_FUNCTIONS_H
# define HIGH_LEVEL_FUNCTIONS_H

# include "scene.h"
# include "image.h"
# include "convas.h"

t_scene	*read_scene(void *mlx_ptr, char *file_name);
void	save_image(t_image *image, t_convas convas, char *scene_name);
void	error_messege(char *err_msg, int my_errno);

#endif
