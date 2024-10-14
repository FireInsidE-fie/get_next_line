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
	char		*buffer;
	static char	*stash;
	
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	stash = malloc(STASH_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{	
		if (!read(fd, buffer, BUFFER_SIZE))
		{
			free(buffer);
			return (NULL);
		}
		ft_strlcat(stash, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_substr(stash, 0, ft_strchr(stash, '\n') - stash + 1));
}

#include <stdio.h>
#include <fcntl.h>

// don't forget to always include a single (or two!) file path, silly
int	main(int argc, char **argv)
{
	int		fd1;
	//int		fd2;
	char	*str;

	if (argc != 2)
		return (0);
	fd1 = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	
	//printf("%s", get_next_line(fd1));
	//printf("%s", get_next_line(fd2));
	//printf("%s", get_next_line(fd1));
	//printf("%s", get_next_line(fd2));
	
	str = get_next_line(fd1);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd1);
	}
	close(fd1);
	//close(fd2);
}
