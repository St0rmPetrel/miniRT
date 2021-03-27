/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: telman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:04:49 by telman            #+#    #+#             */
/*   Updated: 2021/01/18 17:04:57 by telman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_OBJECT_H
# define CREATE_OBJECT_H

# include "objects.h"

int			degree_of_freedom(int type);
t_object	*create_object(char **words, int type);

#endif
