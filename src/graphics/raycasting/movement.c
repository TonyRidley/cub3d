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
static void move_backward(t_app *app);
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

static void move_forward(t_app *app)
{
	double	newX;
	double	newY;

	newX = app->ray.posX + app->ray.dirX;
	newY = app->ray.posY + app->ray.dirY;
	if (!is_wall(app, (int)newX, (int)newY))
	{
		app->ray.posX = newX;
		app->ray.posY = newY;
	}
}

static void move_backward(t_app *app)
{
	double	newX;
	double	newY;

	newX = app->ray.posX - app->ray.dirX;
	newY = app->ray.posY - app->ray.dirY;
		
	if (!is_wall(app, (int)newX, (int)newY))
	{
		app->ray.posX = newX;
		app->ray.posY = newY;
	}
}

static void	strafe_right(t_app *app)
{
	double	strafeX;
	double	strafeY;
	double	newX;
	double	newY;

	strafeX = app->ray.dirY;
	strafeY = -app->ray.dirX;
	newX = app->ray.posX + strafeX;
	newY = app->ray.posY + strafeY;
	if (!is_wall(app, (int)newX, (int)newY))
	{
		app->ray.posX = newX;
		app->ray.posY = newY;
	}
}

static void	strafe_left(t_app *app)
{
	double	strafeX;
	double	strafeY;
	double	newX;
	double	newY;

	strafeX = -app->ray.dirY;
	strafeY = app->ray.dirX;
	newX = app->ray.posX + strafeX;
	newY = app->ray.posY + strafeY;
	if (!is_wall(app, (int)newX, (int)newY))
	{
		app->ray.posX = newX;
		app->ray.posY = newY;
	}
}