/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_app.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:05:28 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 15:05:33 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int	init_app(t_app *app, char *path_to_map)
{
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Starwars: Episode II - Attack of the Clones");
	app->img.img_ptr = mlx_new_image(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	app->img.addr = mlx_get_data_addr(app->img.img_ptr, &app->img.bpp,
			&app->img.line_length, &app->img.endian);
	parse_map(&app, path_to_map);
}
