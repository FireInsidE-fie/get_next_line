/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:06:06 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 16:18:26 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// libraries
# include <stdlib.h> // for malloc() and free()
# include <unistd.h> // for read()

// prototypes
char	*get_next_line(int fd);

#endif

// buffer size default value
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 99
#endif
