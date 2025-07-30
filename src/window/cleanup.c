/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:13:52 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 15:13:54 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cleanup(t_app *app)
{
	if (app && app->img.img_ptr)
	{
		mlx_destroy_image(app->mlx_ptr, app->img.img_ptr);
		app->img.img_ptr = NULL;
	}
	if (app && app->win_ptr)
	{
		mlx_destroy_window(app->mlx_ptr, app->win_ptr);
		app->win_ptr = NULL;
	}
	if (app && app->mlx_ptr)
	{
		mlx_destroy_display(app->mlx_ptr);
		free(app->mlx_ptr);
		app->mlx_ptr = NULL;
	}
}
