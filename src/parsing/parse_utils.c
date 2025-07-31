/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:06 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 14:33:34 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	empty_string(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			str++;
		else
			return (0);
	}
	return (1);
}

int	count_elements(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

char	*skip_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (&str[i]);
}

void	free_rgb_strings(char **rgb_strings)
{
	int	i;

	i = 0;
	while (rgb_strings[i])
	{
		free(rgb_strings[i]);
		i++;
	}
	free(rgb_strings);
}
