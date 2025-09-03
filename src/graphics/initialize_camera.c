/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:38:52 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 14:38:55 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	setup_camera_north(t_app *app);
static void	setup_camera_south(t_app *app);
static void	setup_camera_east(t_app *app);
static void	setup_camera_west(t_app *app);

void	init_camera(t_app *app)
{
	int		x_pos;
	int		y_pos;

	if (find_starting_dir(app, &x_pos, &y_pos))
	{
		app->player.x = y_pos + 0.5;
		app->player.y = x_pos + 0.5;
		app->ray.posX = x_pos + 0.5;
		app->ray.posY = y_pos + 0.5;
		if (app->map[x_pos][y_pos] == 'N')
			setup_camera_north(app);
		else if (app->map[x_pos][y_pos] == 'S')
			setup_camera_south(app);
		else if (app->map[x_pos][y_pos] == 'E')
			setup_camera_east(app);
		else if (app->map[x_pos][y_pos] == 'W')
			setup_camera_west(app);
		app->map[y_pos][x_pos] = '0';
	}
	else
		ft_printf("No starting position found\n");
}

static void	setup_camera_north(t_app *app)
{
	app->ray.dirX = 0;
	app->ray.dirY = -1;
	app->ray.planeX = 0.66;
	app->ray.planeY = 0;
	app->player.angle = deg_to_rad(270);
}

static void	setup_camera_south(t_app *app)
{
	app->ray.dirX = 0;
	app->ray.dirY = 1;
	app->ray.planeX = -0.66;
	app->ray.planeY = 0;
	app->player.angle = deg_to_rad(90);
}

static void	setup_camera_east(t_app *app)
{
	app->ray.dirX = 1;
	app->ray.dirY = 0;
	app->ray.planeX = 0;
	app->ray.planeY = 0.66;
	app->player.angle = deg_to_rad(0);
}

static void	setup_camera_west(t_app *app)
{
	app->ray.dirX = -1;
	app->ray.dirY = 0;
	app->ray.planeX = 0;
	app->ray.planeY = -0.66;
	app->player.angle = deg_to_rad(180);
}
