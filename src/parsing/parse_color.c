/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:46:15 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 14:55:38 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_floor_color(char *line, t_app *app)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (app->config_flags & FLAG_F)
			return (0);
		if (!extract_color(line + 2, app->floor_color))
			return (0);
		app->config_flags |= FLAG_F;
		return (1);
	}
	return (0);
}

int	parse_ceiling_color(char *line, t_app *app)
{
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (app->config_flags & FLAG_C)
			return (0);
		if (!extract_color(line + 2, app->ceiling_color))
			return (0);
		app->config_flags |= FLAG_C;
		return (1);
	}
	return (0);
}
