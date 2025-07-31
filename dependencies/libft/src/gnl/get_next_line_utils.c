/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:41:18 by tridley           #+#    #+#             */
/*   Updated: 2025/01/07 17:59:12 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*start;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	start = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (start);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	char	*p;
	size_t	total_size;
	size_t	i;

	total_size = count * size;
	if (count != 0 && size != 0 && total_size / count != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	p = (char *)ptr;
	i = 0;
	while (i < total_size)
		p[i++] = 0;
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == '\0')
		return (str);
	return (NULL);
}
