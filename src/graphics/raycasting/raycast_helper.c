/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:40:25 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 17:40:28 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg_to_rad(double degrees)
{
	return (degrees * PI / 180.0);
}

double	getTicks(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000.0 + tv.tv_usec / 1000.0);
}

int	is_wall(t_app *app, int x, int y)
{
	if (x < 0 || x >= app->map_width || y < 0 || y >= app->map_height)
		return (1);
	return (app->map[y][x] == '1');
}

int	get_texture_pixel(t_image *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return (*(unsigned int*)dst);
}
