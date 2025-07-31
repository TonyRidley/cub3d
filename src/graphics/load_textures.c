/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 14:48:56 by tridley           #+#    #+#             */
/*   Updated: 2025/07/31 14:48:58 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int load_texture_north(t_app *app, int *width, int *height);
static int load_texture_south(t_app *app, int *width, int *height);
static int load_texture_west(t_app *app, int *width, int *height);
static int load_texture_east(t_app *app, int *width, int *height);

int	load_textures(t_app *app)
{
	int	width;
	int	height;
	
	if (!load_texture_north(app, &width, &height))
		return (0);
	if (!load_texture_south(app, &width, &height))
		return (0);
	if (!load_texture_west(app, &width, &height))
		return (0);
	if (!load_texture_east(app, &width, &height))
		return (0);
	return (1);
}

static int load_texture_north(t_app *app, int *width, int *height)
{
	app->texture_no.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, app->path_no, 
		width, height);
	if (!app->texture_no.img_ptr)
		return (0);
	app->tex_width = *width;
	app->tex_height = *height;
	app->texture_no.addr = mlx_get_data_addr(app->texture_no.img_ptr, 
		&app->texture_no.bpp, &app->texture_no.line_length, &app->texture_no.endian);
	return (1);
}

static int load_texture_south(t_app *app, int *width, int *height)
{
	app->texture_so.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, app->path_so, 
		width, height);
	if (!app->texture_so.img_ptr)
		return (0);
	app->texture_so.addr = mlx_get_data_addr(app->texture_so.img_ptr, 
		&app->texture_so.bpp, &app->texture_so.line_length, &app->texture_so.endian);
	return (1);
}

static int load_texture_west(t_app *app, int *width, int *height)
{
	app->texture_we.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, app->path_we, 
		width, height);
	if (!app->texture_we.img_ptr)
		return (0);
	app->texture_we.addr = mlx_get_data_addr(app->texture_we.img_ptr, 
		&app->texture_we.bpp, &app->texture_we.line_length, &app->texture_we.endian);
	return (1);
}

static int load_texture_east(t_app *app, int *width, int *height)
{
	app->texture_ea.img_ptr = mlx_xpm_file_to_image(app->mlx_ptr, app->path_ea, 
		width, height);
	if (!app->texture_ea.img_ptr)
		return (0);
	app->texture_ea.addr = mlx_get_data_addr(app->texture_ea.img_ptr, 
		&app->texture_ea.bpp, &app->texture_ea.line_length, &app->texture_ea.endian);
	return (1);
}

