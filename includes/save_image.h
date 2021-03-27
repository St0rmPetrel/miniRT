/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:31:00 by telman            #+#    #+#             */
/*   Updated: 2021/01/25 12:35:51 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_IMAGE_H
# define SAVE_IMAGE_H

# include "image.h"
# include "convas.h"

int	save_image_to_fd(int fd, t_image *image, t_convas convas);

#endif
