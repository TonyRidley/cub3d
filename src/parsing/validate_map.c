/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspannin <jspannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 10:26:12 by jspannin          #+#    #+#             */
/*   Updated: 2025/08/07 20:20:14 by jspannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_player_count(t_app *app)
{
	int	player_count;
	int	x;
	int	y;

	player_count = 0;
	y = 0;
	while (y < app->map_height)
	{
		x = 0;
		while (x < app->map_width)
		{
			if (app->map[y][x] == 'N' || app->map[y][x] == 'S'
				|| app->map[y][x] == 'E' || app->map[y][x] == 'W')
			{
				player_count++;
			}
			x++;
		}
		y++;
	}
	return (player_count);
}

int	validate_map(t_app *app)
{
	int	player_count;
	
	player_count = validate_player_count(app);
	if (player_count != 1)
	{
		printf("Error\nMap must have exactly one player\n");
		return (0);
	}
	// if (!flood_fill(app))
	// 	return (0);
	return (1);
}
