/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:43:37 by jspannin          #+#    #+#             */
/*   Updated: 2025/08/06 13:55:02 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_north_texture(char *line, t_app *app)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (app->config_flags & FLAG_NO)
		{
			ft_printf("Error\nduplicate NO texture\n");
			return (0);
		}
		app->path_no = extract_path(line + 3);
		if (!app->path_no)
			return (0);
		app->config_flags |= FLAG_NO;
		return (1);
	}
	return (0);
}

int	parse_south_texture(char *line, t_app *app)
{
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (app->config_flags & FLAG_SO)
		{
			ft_printf("Error\nduplicate SO texture\n");
			return (0);
		}
		app->path_so = extract_path(line + 3);
		if (!app->path_so)
			return (0);
		app->config_flags |= FLAG_SO;
		return (1);
	}
	return (0);
}

int	parse_west_texture(char *line, t_app *app)
{
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (app->config_flags & FLAG_WE)
		{
			ft_printf("Error\nduplicate WE texture\n");
			return (0);
		}
		app->path_we = extract_path(line + 3);
		if (!app->path_we)
			return (0);
		app->config_flags |= FLAG_WE;
		return (1);
	}
	return (0);
}

int	parse_east_texture(char *line, t_app *app)
{
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (app->config_flags & FLAG_EA)
		{
			ft_printf("Error\nduplicate EA texture\n");
			return (0);
		}
		app->path_ea = extract_path(line + 3);
		if (!app->path_ea)
			return (0);
		app->config_flags |= FLAG_EA;
		return (1);
	}
	return (0);
}
