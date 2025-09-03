/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:33:54 by jspannin          #+#    #+#             */
/*   Updated: 2025/08/07 20:05:22 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	process_map_line(char *line, int *max_width, int *line_count)
{
	int		current_length;

	if (is_map_line(line))
	{
		(*line_count)++;
		current_length = ft_strlen(line);
		if (line[current_length - 1] == '\n')
			current_length--;
		if (current_length > *max_width)
			*max_width = current_length;
	}
	else if (empty_string(line))
		return (1);
	else
	{
		printf("Error\nfound invalid map line\n");
		return (0);
	}
	return (1);
}

int	set_map_dimensions(int fd, t_app *app, char *first_line)
{
	int		line_count;
	int		max_width;
	char	*line;

	line_count = 1;
	max_width = ft_strlen(first_line);
	if (first_line[max_width - 1] == '\n')
		max_width--;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_map_line(line, &max_width, &line_count))
		{
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	app->map_width = max_width;
	app->map_height = line_count;
	return (1);
}

static void	process_and_store_line(char *line, char *dest, int map_width)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	ft_strlcpy(dest, line, ft_strlen(line) + 1);
	add_padding_to_line(dest, map_width);
}

// add first_line to map
// re open the file to find the first map_line
// we lost it after setting the map dimensions
// add rest of the map
int	fill_map_data(int fd, t_app *app, char *first_line, char *map_file)
{
	char	*line;
	int		i;

	process_and_store_line(first_line, app->map[0], app->map_width);
	fd = reopen_and_find_map_start(fd, map_file);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	i = 1;
	while (line != NULL)
	{
		if (is_map_line(line))
		{
			process_and_store_line(line, app->map[i], app->map_width);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	parse_map(int fd, t_app *app, char *first_line, char *map_file)
{
	if (!set_map_dimensions(fd, app, first_line))
		return (0);
	if (!allocate_memory_for_map(app))
		return (0);
	if (!fill_map_data(fd, app, first_line, map_file))
	{
		free_map(app);
		return (0);
	}
	return (1);
}
