/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:17:56 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 15:17:59 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

static int	handle_keypress(int keycode, void *param);
static int	handle_destroy(void *param);
// static int	handle_mouse(int button, int x, int y, t_app *app);

void	mlx_hook_handler(t_app app)
{
	mlx_key_hook(app.win_ptr, handle_keypress, &app);
	mlx_hook(app.win_ptr, 17, 0, handle_destroy, &app);
	// mlx_mouse_hook(app.win_ptr, handle_mouse, &app);
}

static int	handle_keypress(int keycode, void *param)
{
	t_app	*app;

	app = (t_app *)param;
	if (keycode == XK_Escape)
		mlx_loop_end(app->mlx_ptr);
	return (0);
}

static int	handle_destroy(void *param)
{
	t_app	*app;

	app = (t_app *)param;
	mlx_loop_end(app->mlx_ptr);
	return (0);
}
//
// static int	handle_mouse(int button, int x, int y, t_app *app)
// {
// 	return (0);
// }