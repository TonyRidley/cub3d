/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:59:28 by tridley           #+#    #+#             */
/*   Updated: 2025/07/30 17:58:26 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <X11/keysym.h>
#include <math.h>
#include <tgmath.h>
#include <sys/time.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 1200
# define FOV 60
# define PI 3.14159265359

# define FLAG_NO 1
# define FLAG_SO 2
# define FLAG_WE 4
# define FLAG_EA 8
# define FLAG_F 16
# define FLAG_C 32
# define ALL_FLAGS 63

typedef struct s_player
{
	double	x;
	double	y;
	double	angle;
}	t_player;

typedef struct s_ray
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_ray;

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

	t_player	player;
	t_ray		ray;

	char	**map;
	int		map_width;
	int		map_height;
	int     config_flags;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;

	t_image	texture_no;
	t_image	texture_so;
	t_image	texture_we;
	t_image	texture_ea;
	int		tex_width;
	int		tex_height;

	int		floor_color[3];
	int		ceiling_color[3];
}	t_app;

// Window
void	ft_mlx_pixel_put(t_image *image, int x, int y, int color);
int		init_app(t_app *app, char *path_to_map);
void	cleanup(t_app *app);
void	mlx_window_hook_handler(t_app app);

// Graphics
void	display(t_app *app);
int		rgb_to_hex(int *rgb_color);
void	init_camera(t_app *app);
int		load_textures(t_app *app);
int		get_texture_pixel(t_image *texture, int x, int y);

// Raycasting
void	cast_rays(t_app *app);
double	deg_to_rad(double degrees);
double	getTicks(void);
int		is_wall(t_app *app, int x, int y);

// Game
void	handle_movement(t_app *app, int keycode);
int		find_starting_dir(char *map[], int width, int height, int *x_pos, int *y_pos);
void	rotate_player_right(t_app *app);
void	rotate_player_left(t_app *app);

// Parsing
int		extract_color(char *line, int color[3]);
char    *extract_path(char *line);
int		parse_floor_color(char *line, t_app *app);
int		parse_ceiling_color(char *line, t_app *app);
int		is_config_line(char *line);
int		parse_config_line(char *line, t_app *app);
int		parsing(t_app *app, char *map_file);
int		get_map_data(int fd, t_app *app, char *first_line);
int		is_map_line(char *line);
int		parse_east_texture(char *line, t_app *app);
int		parse_west_texture(char *line, t_app *app);
int		parse_south_texture(char *line, t_app *app);
int		parse_north_texture(char *line, t_app *app);
void    free_rgb_strings(char **rgb_strings);
char    *skip_whitespace(char *str);
int		count_elements(char **array);
int		empty_string(char *str);
int		validate_config(t_app *app);




void init_test_map(t_app *app);
#endif