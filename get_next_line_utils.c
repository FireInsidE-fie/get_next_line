/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estettle <estettle@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:06:12 by estettle          #+#    #+#             */
/*   Updated: 2024/10/11 16:06:13 by estettle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ft_strlen()
 * returns the size of string *s, trailing null character excluded.
*/
size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s++))
		count++;
	return (count);
}

/* ft_strchr()
 * locates the first occurence of the character c inside of *s, and returns a
 * pointer to it. if nothing is found, returns 0.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

/* ft_substr()
 * allocates a substring from the string s, starting from index start, that is
 * len characters long, then returns it
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (start >= ft_strlen(s) + 1)
		return (malloc(sizeof(char)));
	if (ft_strlen(s) - start < len)
		substring = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	i = 0;
	s += start;
	while (i < len && s[i])
	{
		substring[i] = s[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

/* ft_strlcat()
 * concatenates the *dst and *src strings inside a new string of size dstsize.
 * keep in mind this might cut src or even dst if dstsize if insufficient.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	o_dstsize;

	o_dstsize = ft_strlen(dst);
	i = o_dstsize;
	j = 0;
	if (dstsize && dstsize > o_dstsize)
	{
		while (src[j] && i < dstsize - 1)
			dst[i++] = src[j++];
		dst[i] = '\0';
	}
	if (o_dstsize > dstsize)
		return ((size_t)(dstsize + ft_strlen(src)));
	return ((size_t)(o_dstsize + ft_strlen(src)));
}

/* ft_strjoin()
 * fuses the strings *s1 and *s2 together, null terminating the resulting string
 * and returning it.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(ft_strlen(s1) + BUFFER_SIZE + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (*s1)
	{
		joined[i++] = *s1;
		s1++;
	}
	j = 0;
	while (j < BUFFER_SIZE && s2[j])
	{
		joined[i++] = s2[j];
		j++;
	}
	joined[i] = '\0';
	return (joined);
}
