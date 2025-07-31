/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:17:56 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 11:41:31 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static int	handle_keypress(int keycode, void *param);
static int	handle_window_destroy(void *param);

void	mlx_window_hook_handler(t_app app)
{
	mlx_key_hook(app.win_ptr, handle_keypress, &app);
	mlx_hook(app.win_ptr, 17, 0, handle_window_destroy, &app);
}

static int	handle_keypress(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == XK_Escape)
	{
		mlx_loop_end(app->mlx_ptr);
		return (0);
	}
	if (keycode == 'w' || keycode == 'W' || keycode == 's' || keycode == 'S' ||
		keycode == XK_Left || keycode == XK_Right || keycode == 'a' || keycode == 'A' ||
		keycode == 'd' || keycode == 'D')
	{
		handle_movement(app, keycode);
		display(app);
	}
	
	return (0);
}

static int	handle_window_destroy(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	mlx_loop_end(app->mlx_ptr);
	return (0);
}