/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:14:04 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 16:14:06 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_floor(t_app *app, int floor_color);
static void	fill_ceiling(t_app *app, int ceiling_color);

void	display(t_app *app)
{
	int	floor_color;
	int	ceiling_color;

	floor_color = rgb_to_hex(app->floor_color);
	ceiling_color = rgb_to_hex(app->ceiling_color);
	fill_ceiling(app, ceiling_color);
	fill_floor(app, floor_color);
	cast_rays(app);

	mlx_put_image_to_window(app->mlx_ptr, app->win_ptr, app->img.img_ptr, 0, 0);
}

static void fill_floor(t_app *app, int floor_color)
{
	int x = 0;
	int y = WIN_HEIGHT / 2;
	
	while (x < WIN_WIDTH)
	{
		y = WIN_HEIGHT / 2;
		while (y < WIN_HEIGHT)
		{
			ft_mlx_pixel_put(&app->img, x, y, floor_color);
			y++;
		}
		x++;
	}
}

static void fill_ceiling(t_app *app, int ceiling_color)
{
	int x = 0;
	int y = 0;
	
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			ft_mlx_pixel_put(&app->img, x, y, ceiling_color);
			y++;
		}
		x++;
	}
}