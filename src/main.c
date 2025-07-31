/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 13:53:13 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 16:29:38 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

int main(int argc, char *argv[])
{
	t_app	app;

	if (argc != 2)
		return (ft_putstr_fd("Invalid number of arguments. Please use ./cub3d path/to/the/map\n", 2), 1);
	ft_memset(&app, 0, sizeof(t_app));
	if (init_app(&app, argv[2]))
		return (1);
	display(&app);
	mlx_window_hook_handler(app);
	mlx_loop(app.mlx_ptr);
	cleanup(&app);
	return (0);
}

