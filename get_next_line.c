/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:06:01 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 16:11:08 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}

#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}
