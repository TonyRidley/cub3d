/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:39:58 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 13:03:16 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_fps_info(void)
{
	static double	time;
	static double	old_time;
	double			frame_time;

	if (!time)
		time = 0;
	if (!old_time)
		old_time = 0;
	old_time = time;
	time = get_ticks();
	frame_time = (time - old_time) / 1000.0;
	if (frame_time > 0)
		printf("FPS: %.1f\n", 1.0 / frame_time);
}

static void	update_player_position(t_app *app)
{
	app->player.x = app->ray.posX;
	app->player.y = app->ray.posY;
	app->player.angle = atan2(app->ray.dirY, app->ray.dirX);
}

void	cast_rays(t_app *app)
{
	int				x;
	t_raycast_data	ray_data;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray_calculation(app, x, &ray_data);
		perform_raycast_calculation(app, &ray_data);
		render_wall_stripe(app, &ray_data, x);
		x++;
	}
	display_fps_info();
	update_player_position(app);
}

void	perform_raycast_calculation(t_app *app, t_raycast_data *data)
{
	calculate_step_and_sidedist(app, data);
	perform_dda(app, data);
	calculate_wall_params(data);
	calculate_texture_data(app, data);
}
