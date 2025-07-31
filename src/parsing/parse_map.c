/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:33:54 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 15:29:26 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	char	*trimmed;
	int		i;

	trimmed = skip_whitespace(line);
	if (!trimmed || *trimmed == '\0' || *trimmed == '\n')
		return (0);

	i = 0;
	while (trimmed[i] && trimmed[i] != '\n')
	{
		if (trimmed[i] != '0' && trimmed[i] != '1' && trimmed[i] != ' ' &&
			trimmed[i] != 'N' && trimmed[i] != 'S' && 
			trimmed[i] != 'E' && trimmed[i] != 'W')
			return (0);
		i++;
	}
	// Map regel moet minstens 1 karakter hebben (na whitespace)
	return (i > 0);

}

/**
 * Eenvoudige versie van get_map_data
 * Leest alle map regels en maakt 2D array
 */
int	get_map_data(int fd, t_app *app, char *first_line)
{
	char	**temp_lines;
	char	*line;
	int		count;
	int		max_width;
	int		i;

	// Stap 1: Verzamel alle map regels in temp array
	temp_lines = malloc(sizeof(char *) * 1000);  // Max 1000 regels
	if (!temp_lines)
		return (0);
	
	count = 0;
	max_width = 0;
	
	// Voeg eerste regel toe
	if (first_line && is_map_line(first_line))
	{
		temp_lines[count] = ft_strdup(first_line);
		if (ft_strlen(first_line) > max_width)
			max_width = ft_strlen(first_line);
		count++;
	}
	
	// Lees rest van map regels
	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line))
		{
			temp_lines[count] = ft_strdup(line);
			if (ft_strlen(line) > max_width)
				max_width = ft_strlen(line);
			count++;
		}
		else if (line[0] != '\n' && line[0] != '\0')  // Non-empty, non-map = error
		{
			free(line);
			// Cleanup temp array
			for (i = 0; i < count; i++)
				free(temp_lines[i]);
			free(temp_lines);
			return (0);
		}
		free(line);
	}
	
	if (count == 0)
	{
		free(temp_lines);
		return (0);  // Geen map data gevonden
	}
	
	// Stap 2: Stel dimensies in
	app->map_height = count;
	app->map_width = max_width - 1;  // -1 voor newline
	
	// Stap 3: Alloceer finale map
	app->map = malloc(sizeof(char *) * (count + 1));
	if (!app->map)
	{
		for (i = 0; i < count; i++)
			free(temp_lines[i]);
		free(temp_lines);
		return (0);
	}
	
	// Stap 4: Kopieer regels naar finale map
	i = 0;
	while (i < count)
	{
		app->map[i] = malloc(sizeof(char) * (app->map_width + 1));
		if (!app->map[i])
		{
			// Cleanup bij error
			while (--i >= 0)
				free(app->map[i]);
			free(app->map);
			for (i = 0; i < count; i++)
				free(temp_lines[i]);
			free(temp_lines);
			return (0);
		}
		
		// Kopieer regel (zonder newline)
		ft_memset(app->map[i], ' ', app->map_width);  // Vul met spaties
		ft_strncpy(app->map[i], temp_lines[i], 
			ft_strlen(temp_lines[i]) - 1);  // -1 voor newline
		app->map[i][app->map_width] = '\0';
		
		free(temp_lines[i]);
		i++;
	}
	app->map[count] = NULL;  // NULL terminate
	free(temp_lines);
	
	return (1);  // Success
}
