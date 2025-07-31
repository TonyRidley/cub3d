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

#include <stdbool.h>
#include "cub3d.h"

void	cast_rays(t_app *app)
{
	int w = WIN_WIDTH;
	int h = WIN_HEIGHT;
	
	static double time = 0;
	static double oldTime = 0;

	for(int x = 0; x < w; x++)
	{
		//calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1;
		double rayDirX = app->ray.dirX + app->ray.planeX * cameraX;
		double rayDirY = app->ray.dirY + app->ray.planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)app->ray.posX;
		int mapY = (int)app->ray.posY;

		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0;
		int side;
		
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (app->ray.posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - app->ray.posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (app->ray.posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - app->ray.posY) * deltaDistY;
		}
		
		//perform DDA
		while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (is_wall(app, mapX, mapY))
				hit = 1;
		}
		
		//Calculate distance projected on camera direction
		if(side == 0) perpWallDist = (sideDistX - deltaDistX);
		else          perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if(drawEnd >= h) drawEnd = h - 1;

		// TEXTURE CALCULATIONS
		// Calculate where exactly the wall was hit
		double wallX;
		if (side == 0) wallX = app->ray.posY + perpWallDist * rayDirY;
		else           wallX = app->ray.posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		// x coordinate on the texture
		int texX = (int)(wallX * (double)app->tex_width);
		if(side == 0 && rayDirX > 0) texX = app->tex_width - texX - 1;
		if(side == 1 && rayDirY < 0) texX = app->tex_width - texX - 1;

		// Choose texture based on wall direction
		t_image *current_texture;
		if (side == 0) // EW wall
		{
			if (rayDirX > 0) current_texture = &app->texture_we; // West
			else             current_texture = &app->texture_ea; // East
		}
		else // NS wall
		{
			if (rayDirY > 0) current_texture = &app->texture_no; // North
			else             current_texture = &app->texture_so; // South
		}

		// Draw the textured wall stripe
		double step = 1.0 * app->tex_height / lineHeight;
		double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
		
		for(int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (app->tex_height - 1);
			texPos += step;
			int color = get_texture_pixel(current_texture, texX, texY);
			ft_mlx_pixel_put(&app->img, x, y, color);
		}
	}
	
	// Rest of your timing code...
	oldTime = time;
	time = getTicks();
	double frameTime = (time - oldTime) / 1000.0;
	if (frameTime > 0)
		printf("FPS: %.1f\n", 1.0 / frameTime);
	
	app->player.x = app->ray.posX;
	app->player.y = app->ray.posY;
	app->player.angle = atan2(app->ray.dirY, app->ray.dirX);
}
