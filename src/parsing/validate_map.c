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

int validate_player_count(t_app *app)
{
    int player_count;
    int x;
    int y;
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
void    free_map_copy(char **map_copy, int height)
{
    int i;
    i = 0;
    while(i < height)
    {
        if (map_copy[i])
            free(map_copy[i]);
        i++;
    }
    free(map_copy);
}
char **copy_map(t_app *app)
{
    char    **map_copy;
    int     i;
    i = 0;
    map_copy = malloc(sizeof(char *) * app->map_height);
    if (!map_copy)
        return (NULL);
    while (i < app->map_height)
    {
        map_copy[i] = malloc(app->map_width + 1);
        if (!map_copy[i])
        {
            free_map_copy(map_copy, i);
            return (NULL);
        }
        ft_strlcpy(map_copy[i], app->map[i], app->map_width + 1);
        i++;
    }
    return (map_copy);
}
int find_player_position(t_app *app, int *player_x, int *player_y)
{
    int x;
    int y;
    y = 0;
    while (y < app->map_height)
    {
        x = 0;
        while (x < app->map_width)
        {
            if (app->map[y][x] == 'N' || app->map[y][x] == 'S'
                || app->map[y][x] == 'E' || app->map[y][x] == 'W')
            {
                *player_x = x;
                *player_y = y;
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}
void    flood_fill(char **map, int x, int y, t_app *app, int *reached_edge)
{
    if (x < 0 || y < 0 || x >= app->map_width || y >= app->map_height)
    {
        *reached_edge = 1;
        return ;
    }
    if (map[y][x] == '1' || map[y][x] == 'F')
        return ;
    map[y][x] = 'F';
    flood_fill(map, x + 1, y, app, reached_edge);
    flood_fill(map, x - 1, y, app, reached_edge);
    flood_fill(map, x, y + 1, app, reached_edge);
    flood_fill(map, x, y - 1, app, reached_edge);
}
int flood_fill_map(t_app *app)
{
    char    **map_copy;
    int     player_x;
    int     player_y;
    int     reached_edge;
    reached_edge = 0;
    map_copy = copy_map(app);
    if (!map_copy)
        return (0);
    if (!find_player_position(app, &player_x, &player_y))
    {
        free_map_copy(map_copy, app->map_height);
        return (0);
    }
    flood_fill(map_copy, player_x, player_y, app, &reached_edge);
    free_map_copy(map_copy, app->map_height);
    if (reached_edge)
    {
        printf("Error\nMap is not enclosed by walls\n");
        return (0);
    }
    return (1);
}
int validate_map(t_app *app)
{
    int player_count;
    player_count = validate_player_count(app);
    if (player_count != 1)
    {
        printf("Error\nMap must have exactly one player\n");
        return (0);
    }
    if (!flood_fill_map(app))
        return (0);
    return (1);
}