/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:06:16 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 14:06:40 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*extract_path(char *line)
{
	char	*start;
	char	*end;
	int		len;
	char	*path;

	start = skip_whitespace(line);
	end = start;
	while (*end && *end != '\n' && *end != ' ' && *end != '\t')
		end++;
	len = end - start;
	path = malloc(len + 1);
	if (!path)
		return (NULL);
	ft_strlcpy(path, start, len + 1);
	return (path);
}
