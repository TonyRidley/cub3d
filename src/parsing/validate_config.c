/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_config.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:09 by jspannin          #+#    #+#             */
/*   Updated: 2025/07/31 15:37:51 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_configs_found(t_app *app)
{
	return ((app->config_flags & ALL_FLAGS) == ALL_FLAGS);
}

// static int	validate_texture_path(char *path)
// {
// 	// to do
// }
//
// static int	validate_color_values(int color[3])
// {
// 	// to do of doe ik eigenlijk al na atoi
// }

int	validate_config(t_app *app)
{
	if (!all_configs_found(app))
	{
		ft_printf("Error: missing configurations\n");
		return (0);
	}
	// if (!validate_texture_path)
	// {
	// 	ft_printf("Error\nsomething wrong with path");
	// 	return (0);
	// }
	return (1);
}