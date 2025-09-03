/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:09:38 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 15:09:41 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward(t_app *app);
static void	move_backward(t_app *app);
static void	strafe_right(t_app *app);
static void	strafe_left(t_app *app);

void	handle_movement(t_app *app, int keycode)
{
	if (keycode == 'w' || keycode == 'W')
		move_forward(app);
	if (keycode == 's' || keycode == 'S')
		move_backward(app);
	if (keycode == 'a' || keycode == 'A')
		strafe_right(app);
	if (keycode == 'd' || keycode == 'D')
		strafe_left(app);
	if (keycode == XK_Right)
		rotate_player_right(app);
	if (keycode == XK_Left)
		rotate_player_left(app);
}

static void	move_forward(t_app *app)
{
	double	new_x;
	double	new_y;

	new_x = app->ray.posX + app->ray.dirX;
	new_y = app->ray.posY + app->ray.dirY;
	if (!is_wall(app, (int)new_x, (int)new_y))
	{
		app->ray.posX = new_x;
		app->ray.posY = new_y;
	}
}

static void	move_backward(t_app *app)
{
	double	new_x;
	double	new_y;

	new_x = app->ray.posX - app->ray.dirX;
	new_y = app->ray.posY - app->ray.dirY;
	if (!is_wall(app, (int)new_x, (int)new_y))
	{
		app->ray.posX = new_x;
		app->ray.posY = new_y;
	}
}

static void	strafe_right(t_app *app)
{
	double	strafe_x;
	double	strafe_y;
	double	new_x;
	double	new_y;

	strafe_x = app->ray.dirY;
	strafe_y = -app->ray.dirX;
	new_x = app->ray.posX + strafe_y;
	new_y = app->ray.posY + strafe_y;
	if (!is_wall(app, (int)new_x, (int)new_y))
	{
		app->ray.posX = new_x;
		app->ray.posY = new_y;
	}
}

static void	strafe_left(t_app *app)
{
	double	strafe_x;
	double	strafe_y;
	double	new_x;
	double	new_y;

	strafe_x = -app->ray.dirY;
	strafe_y = app->ray.dirX;
	new_x = app->ray.posX + strafe_x;
	new_y = app->ray.posY + strafe_y;
	if (!is_wall(app, (int)new_x, (int)new_y))
	{
		app->ray.posX = new_x;
		app->ray.posY = new_y;
	}
}
