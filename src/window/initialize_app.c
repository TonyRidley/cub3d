/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_app.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:05:28 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 12:56:59 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

int	init_app(t_app *app, char *path_to_map)
{
	(void)path_to_map;
	app->mlx_ptr = mlx_init();
	app->win_ptr = mlx_new_window(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"Starwars: Episode II - Attack of the Clones");
	app->img.img_ptr = mlx_new_image(app->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	app->img.addr = mlx_get_data_addr(app->img.img_ptr, &app->img.bpp,
			&app->img.line_length, &app->img.endian);
	printf("path: %s\n", path_to_map);
	if (!parsing(app, path_to_map))
		return (1);
	init_camera(app);
	if (!load_textures(app))
	{
		printf("Error loading textures\n");
		return (1);
	}
	return (0);
}

int	find_starting_dir(t_app *app, int *x_pos, int *y_pos)
{
	int	x;
	int	y;
	int	square;

	x = 0;
	while (x < app->map_width)
	{
		y = 0;
		while (y < app->map_height)
		{
			square = app->map[x][y];
			if (square == 'N' || square == 'S' || square == 'E'
				|| square == 'W')
			{
				*x_pos = x;
				*y_pos = y;
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}
