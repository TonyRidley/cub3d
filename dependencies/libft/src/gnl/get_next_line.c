/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:40:34 by tridley           #+#    #+#             */
/*   Updated: 2025/01/07 17:55:46 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_join_and_free(char *s1, char *s2)
{
	char	*result;

	if (!s1 || !s2)
		return (free(s1), NULL);
	result = ft_strjoingnl(s1, s2);
	if (!result)
		return (free(s1), NULL);
	return (free(s1), result);
}

char	*read_first_line(int fd, char *text)
{
	char	*buffer;
	int		bytes_read;

	if (!text)
		text = ft_calloc(1, 1);
	if (!text)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(text), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(text), NULL);
		buffer[bytes_read] = '\0';
		text = ft_join_and_free(text, buffer);
		if (!text)
			return (free(buffer), NULL);
		if (ft_strchr(text, '\n'))
			break ;
	}
	return (free(buffer), text);
}

char	*ft_get_line(char *text)
{
	int		i;
	char	*str;

	if (!text || !*text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		str = malloc(i + 2);
	else
		str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		str[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*clean_first_line(char *text)
{
	int		i;
	int		j;
	char	*str;

	if (!text)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
		return (free(text), NULL);
	str = ft_calloc(ft_strlen(text + i), sizeof(char));
	if (!str)
		return (free(text), NULL);
	i++;
	j = 0;
	while (text[i])
		str[j++] = text[i++];
	return (free(text), str);
}

char	*get_next_line(int fd)
{
	char		*output_text;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = read_first_line(fd, text);
	if (!text)
		return (NULL);
	output_text = ft_get_line(text);
	if (!output_text)
		return (free(text), text = NULL, NULL);
	text = clean_first_line(text);
	return (output_text);
}
