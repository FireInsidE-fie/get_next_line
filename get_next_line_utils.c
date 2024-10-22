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

#include "get_next_line_bonus.h"

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

/* ft_calloc()
 * allocates memory according to count * size bytes, then sets it all to 0
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*area;
	size_t	b_size;

	b_size = count * size;
	area = malloc(b_size);
	if (!area)
		return (NULL);
	while (b_size)
		*(char *)(area + --b_size) = 0;
	return (area);
}

/* ft_strchr()
 * locates the first occurence of the character c inside of *s, and returns a
 * pointer to it. if nothing is found, returns 0.
*/
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
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
	size_t	s_length;

	s_length = ft_strlen(s);
	if (start >= s_length + 1)
		return (malloc(sizeof(char)));
	if (ft_strlen(s) - start < len)
		substring = malloc((s_length - start + 1) * sizeof(char));
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

/* ft_strjoin()
 * fuses the strings *s1 and *s2 together, null terminating the resulting string
 * and returning it.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	s1_length;
	size_t	s2_length;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	joined = malloc(s1_length + s2_length + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (*s1)
	{
		joined[i++] = *s1;
		s1++;
	}
	j = 0;
	while (j < s2_length && s2[j])
	{
		joined[i++] = s2[j];
		j++;
	}
	joined[i] = '\0';
	return (joined);
}
