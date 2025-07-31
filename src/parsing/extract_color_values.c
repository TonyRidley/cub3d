/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color_values.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:01:04 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 15:36:58 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_rgb_content(char **rgb_strings)
{
	int	i;
	int	j;

	i = 0;
	while (rgb_strings[i])
	{
		if (empty_string(rgb_strings[i]))
		{
			ft_printf("Error\nRGB value cannot be empty\n");
			return (0);
		}
		j = 0;
		while (rgb_strings[i][j])
		{
			if (!ft_isdigit(rgb_strings[i][j]) && !ft_isspace(rgb_strings[i][j]))
			{
				ft_printf("Error\nRGB must contain digits only\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_rgb_strings(char **rgb_strings)
{
	if (count_elements(rgb_strings) != 3)
	{
		ft_printf("Error\nRGB must have exactly 3 values\n");
		return (0);
	}
	if (!validate_rgb_content(rgb_strings))
		return (0);
	return (1);
}

static int	convert_to_rgb_values(char **rgb_strings, int color[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		color[i] = ft_atoi(rgb_strings[i]);
		if (color[i] < 0 || color[i] > 255)
		{
			ft_printf("Error\nRGB values must be between 0-255\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static char	**parse_rgb_string(char *line)
{
	char	*start;
	char	**rgb_strings;

	start = skip_whitespace(line);
	rgb_strings = ft_split(start, ',');
	if (!rgb_strings)
		return (NULL);
	if (!validate_rgb_strings(rgb_strings))
	{
		free_rgb_strings(rgb_strings);
		return (NULL);
	}
	return (rgb_strings);
}

int	extract_color(char *line, int color[3])
{
	char	**rgb_strings;

	rgb_strings = parse_rgb_string(line);
	if (!rgb_strings)
		return (0);
	if (!convert_to_rgb_values(rgb_strings, color))
	{
		free_rgb_strings(rgb_strings);
		return (0);
	}
	free_rgb_strings(rgb_strings);
	return (1);
}
