/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:00:00 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 15:00:00 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "cub3d.h"

void	init_ray_calculation(t_app *app, int x, t_raycast_data *data)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	data->rayDirX = app->ray.dirX + app->ray.planeX * camera_x;
	data->rayDirY = app->ray.dirY + app->ray.planeY * camera_x;
	data->mapX = (int)app->ray.posX;
	data->mapY = (int)app->ray.posY;
}

void	calculate_step_and_sidedist(t_app *app, t_raycast_data *data)
{
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (app->ray.posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - app->ray.posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (app->ray.posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - app->ray.posY) * data->deltaDistY;
	}
}

void	perform_dda(t_app *app, t_raycast_data *data)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		if (is_wall(app, data->mapX, data->mapY))
			hit = 1;
	}
}

void	calculate_wall_params(t_raycast_data *data)
{
	if (data->side == 0)
		data->perpWallDist = (data->sideDistX - data->deltaDistX);
	else
		data->perpWallDist = (data->sideDistY - data->deltaDistY);
	data->lineHeight = (int)(WIN_HEIGHT / data->perpWallDist);
	data->drawStart = -data->lineHeight / 2 + WIN_HEIGHT / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + WIN_HEIGHT / 2;
	if (data->drawEnd >= WIN_HEIGHT)
		data->drawEnd = WIN_HEIGHT - 1;
}

void	calculate_texture_data(t_app *app, t_raycast_data *data)
{
	double	wall_x;

	if (data->side == 0)
		wall_x = app->ray.posY + data->perpWallDist * data->rayDirY;
	else
		wall_x = app->ray.posX + data->perpWallDist * data->rayDirX;
	wall_x -= floor(wall_x);
	data->texX = (int)(wall_x * (double)app->tex_width);
	if ((data->side == 0 && data->rayDirX > 0)
		|| (data->side == 1 && data->rayDirY < 0))
		data->texX = app->tex_width - data->texX - 1;
	if (data->side == 0 && data->rayDirX > 0)
		data->current_texture = &app->texture_we;
	else if (data->side == 0)
		data->current_texture = &app->texture_ea;
	else if (data->rayDirY > 0)
		data->current_texture = &app->texture_no;
	else
		data->current_texture = &app->texture_so;
}
