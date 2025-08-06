/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:09 by jspannin          #+#    #+#             */
/*   Updated: 2025/08/06 14:49:15 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_configs_found(t_app *app)
{
	if ((app->config_flags & ALL_FLAGS) != ALL_FLAGS)
	{
		ft_printf("Error\nmissing configurations\n");
		return (0);
	}
	return (1);
}

static int	check_texture_file(char *path, char *name)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n%s texture file not found or not readable\n", name);
		return (0);
	}
	close(fd);
	return (1);
}

static int	validate_texture_path(t_app *app)
{
	if (!check_texture_file(app->path_no, "NO_TEXTURE_FILE"))
		return (0);
	if (!check_texture_file(app->path_so, "SO_TEXTURE_FILE"))
		return (0);
	if (!check_texture_file(app->path_we, "WE_TEXTURE_FILE"))
		return (0);
	if (!check_texture_file(app->path_ea, "EA_TEXTURE_FILE"))
		return (0);
	return (1);
}

int	validate_config(t_app *app)
{
	if (!all_configs_found(app))
		return (0);
	if (!validate_texture_path(app))
		return (0);
	return (1);
}
