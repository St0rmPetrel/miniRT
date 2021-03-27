/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image_functions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:30:45 by telman            #+#    #+#             */
/*   Updated: 2021/01/23 15:48:46 by serma            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_IMAGE_FUNCTIONS_H
# define SAVE_IMAGE_FUNCTIONS_H

# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40
# define BYTES_PER_PIXEL 3

# include "image.h"

void	write_image(int fd, t_image *image, int width, int height);
int		write_info_header(int fd, int width, int height);
int		write_file_header(int fd, int width, int height);

#endif
