/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:59:28 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 15:16:47 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <X11/keysym.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_app
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	img;

	char	**map;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		floor_color[3];
	int		ceiling_color[3];
}	t_app;

int		run_app(t_app app);

// Window
void	ft_mlx_pixel_put(t_image *image, int x, int y, int color);
int		init_app(t_app *app, char *path_to_map);
void	cleanup(t_app *app);
void	mlx_hook_handler(t_app app);

// Graphics
void	display_map(t_app app);
int		rgb_to_hex(int *rgb_color);

#endif
