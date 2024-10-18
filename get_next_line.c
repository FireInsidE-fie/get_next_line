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

/* parse_line()
 *
*/
static char	*parse_line(char **stash, int fd)
{
	char		*buffer;
	char		*tmp;

	if (ft_strchr(*stash, '\n'))
		return (ft_substr(*stash, 0, ft_strchr(*stash, '\n') - *stash + 1));
	buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	/**************************************************************************/
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_strjoin(*stash, buffer);
	free(*stash);
	if (!tmp)
	{
		free(buffer);
		return (NULL);
	}
	*stash = tmp;
	/**************************************************************************/
	while (!ft_strchr(*stash, '\n'))
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			if (read(fd, buffer, BUFFER_SIZE) == 0)
			{
				free(buffer);
				return (ft_strjoin("", *stash)); // leak?
			}
			free(buffer);
			free(*stash);
			*stash = NULL;
			return (NULL);
		}
		tmp = ft_strjoin(*stash, buffer);
		free(*stash);
		if (!tmp)
		{
			free(buffer);
			*stash = NULL;
			return (NULL);
		}
		*stash = tmp;
	}
	free(buffer);
	if (ft_strchr(*stash, '\n'))
		return (ft_substr(*stash, 0, ft_strchr(*stash, '\n') - *stash + 1));
	return (ft_substr(*stash, 0, ft_strlen(*stash)));
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*tmp;
	static char	*stash;

	if (read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(sizeof(char));
		if (!stash)
			return (NULL);
		*stash = '\0';
	}
	line = parse_line(&stash, fd);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (ft_strchr(stash, '\n'))
	{
		tmp = ft_substr(stash, ft_strchr(stash, '\n') - stash + 1,
				ft_strlen(stash) - (ft_strchr(stash, '\n') - stash));
		free(stash);
		if (!tmp)
		{
			free(line);
			stash = NULL;
			return (NULL);
		}
		stash = tmp;
	}
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

// don't forget to always include a single (or two!) file path, silly
int	main(int argc, char **argv)
{
	//int		fd1;
	int		fd2;
	char	*str;

	if (argc != 2)
		return (0);

	// fd1 = open(argv[1], O_RDONLY);
	
	// printf("[!] - Reading two lines...\n");
	// printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd1));

	// close(fd1);

	fd2 = open(argv[1], O_RDONLY);

	printf("\n\n[!] - Reading entire file...\n");
	str = get_next_line(fd2);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd2);
	}

	free(str);

	close(fd2);
}
