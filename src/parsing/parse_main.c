/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:01 by jspannin          #+#    #+#             */
/*   Updated: 2025/08/07 20:05:05 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_configurations(int fd, t_app *app)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (is_config_line(line))
		{
			if (!parse_config_line(line, app))
				return (free(line), NULL);
			free(line);
		}
		else if (is_map_line(line))
			return (line);
		else
		{
			if (line[0] != '\n')
				return (free(line), NULL);
			free(line);
		}
		line = get_next_line(fd);
	}
	return (NULL);
}

static int	configurations_part(int fd, t_app *app, char **first_line)
{
	*first_line = get_configurations(fd, app);
	if (!*first_line)
	{
		close(fd);
		printf("Error\nconfiguration parsing failed or no map found\n");
		return (0);
	}
	if (!validate_config(app))
	{
		free(*first_line);
		close(fd);
		return (0);
	}
	return (1);
}

static int	map_part(int fd, t_app *app, char *first_line, char *map_file)
{
	if (!parse_map(fd, app, first_line, map_file))
	{
		free(first_line);
		close(fd);
		return (0);
	}
	if (!validate_map(app))
	{
		free(first_line);
		close(fd);
		return (0);
	}
	return (1);
}

int	parsing(t_app *app, char *map_file)
{
	int		fd;
	char	*first_line;

	if (!ft_strnstr(map_file, ".cub", ft_strlen(map_file)))
		return (printf("Error\nincorrect file name\n"), 0);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (printf("Error\ncouldn't open file\n"), 0);
	if (!configurations_part(fd, app, &first_line))
		return (0);
	if (!map_part(fd, app, first_line, map_file))
		return (0);
	free(first_line);
	close(fd);
	return (1);
}
