/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:27:19 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 15:27:22 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void rotate_player_right(t_app *app)
{
	app->player.angle += PI / 8.0;
	if (app->player.angle >= 2 * PI)
		app->player.angle -= 2 * PI;
	app->ray.dirX = cos(app->player.angle);
	app->ray.dirY = sin(app->player.angle);
	app->ray.planeX = -sin(app->player.angle) * 0.66;
	app->ray.planeY = cos(app->player.angle) * 0.66;
}

void rotate_player_left(t_app *app)
{
	app->player.angle -= PI / 8.0;
	if (app->player.angle < 0)
		app->player.angle += 2 * PI;
	app->ray.dirX = cos(app->player.angle);
	app->ray.dirY = sin(app->player.angle);
	app->ray.planeX = -sin(app->player.angle) * 0.66;
	app->ray.planeY = cos(app->player.angle) * 0.66;
}
