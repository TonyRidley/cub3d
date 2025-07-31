/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:01 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 15:37:11 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_configurations(int fd, t_app *app)
{
	char	*line;

	while ((line = get_next_line(fd)) != NULL)
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
			free(line);
	}
	return (NULL);
}

int	parsing(t_app *app, char *map_file)
{
	int		fd;
	char	*first_line;

	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);

	first_line = get_configurations(fd, app);
	if (!first_line)
	{
		close(fd);
		printf("Error: configuration parsing failed or no map found");
		return (0);
	}

	if (!validate_config(app))
	{
		free(first_line);
		close(fd);
		return (0);
	}

	if (!get_map_data(fd, app, first_line))
	{
		free(first_line);
		close(fd);
		return (0);
	}
	free(first_line);
	close (fd);
	return (1); // success
}
