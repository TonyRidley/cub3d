/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:25:58 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 14:56:10 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_config_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	parse_config_line(char *line, t_app *app)
{
	if (parse_north_texture(line, app))
		return (1);
	if (parse_south_texture(line, app))
		return (1);
	if (parse_west_texture(line, app))
		return (1);
	if (parse_east_texture(line, app))
		return (1);
	if (parse_floor_color(line, app))
		return (1);
	if (parse_ceiling_color(line, app))
		return (1);
	return (0);
}
