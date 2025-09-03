/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 19:20:16 by jspannin          #+#    #+#             */
/*   Updated: 2025/08/07 19:31:13 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_app *app)
{
	int	i;

	if (!app->map)
		return ;
	i = 0;
	while (i < app->map_height)
	{
		if (app->map[i])
			free(app->map[i]);
		i++;
	}
	free(app->map);
	app->map = NULL;
}

int	is_map_line(char *line)
{
	int	i;

	line = skip_whitespace(line);
	if (!line || *line == '\0' || *line == '\n')
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			return (0);
		i++;
	}
	return (i > 0);
}

int	add_padding_to_line(char *map_line, int map_width)
{
	int	current_len;

	current_len = ft_strlen(map_line);
	while (current_len < map_width)
	{
		map_line[current_len] = ' ';
		current_len++;
	}
	map_line[map_width] = '\0';
	return (1);
}

// memory alloceren voor de map
int	allocate_memory_for_map(t_app *app)
{
	int	i;

	i = 0;
	app->map = malloc(sizeof(char *) * app->map_height);
	if (!app->map)
		return (0);
	while (i < app->map_height)
	{
		app->map[i] = malloc(app->map_width + 1);
		if (!app->map[i])
		{
			free_map(app);
			return (0);
		}
		i++;
	}
	return (1);
}

int	reopen_and_find_map_start(int fd, char *map_file)
{
	char	*line;

	close(fd);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			free(line);
			return (fd);
		}
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (-1);
}
