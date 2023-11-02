/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:28:45 by escastel          #+#    #+#             */
/*   Updated: 2023/11/02 14:41:49 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	png_to_txt_img(t_slong *g)
{
	g->txt_player_right = mlx_load_png("sprite/player_right.png");
	g->img_player_right = mlx_texture_to_image(g->mlx, g->txt_player_right);
	g->txt_player_frnt = mlx_load_png("sprite/player_front.png");
	g->img_player_frnt = mlx_texture_to_image(g->mlx, g->txt_player_frnt);
	g->txt_player_left = mlx_load_png("sprite/player_left.png");
	g->img_player_left = mlx_texture_to_image(g->mlx, g->txt_player_left);
	g->txt_player_back = mlx_load_png("sprite/player_back.png");
	g->img_player_back = mlx_texture_to_image(g->mlx, g->txt_player_back);
	g->txt_colection = mlx_load_png("sprite/colection.png");
	g->img_colection = mlx_texture_to_image(g->mlx, g->txt_colection);
	g->txt_wall = mlx_load_png("sprite/wall.png");
	g->img_wall = mlx_texture_to_image(g->mlx, g->txt_wall);
	g->txt_floor = mlx_load_png("sprite/floor.png");
	g->img_floor = mlx_texture_to_image(g->mlx, g->txt_floor);
	g->txt_player_exit = mlx_load_png("sprite/player_exit.png");
	g->img_player_exit = mlx_texture_to_image(g->mlx, g->txt_player_exit);
	g->txt_exit_close = mlx_load_png("sprite/exit_close.png");
	g->img_exit_close = mlx_texture_to_image(g->mlx, g->txt_exit_close);
	g->txt_exit_open = mlx_load_png("sprite/exit_open.png");
	g->img_exit_open = mlx_texture_to_image(g->mlx, g->txt_exit_open);
	g->txt_enemy = mlx_load_png("sprite/enemy.png");
	g->img_enemy = mlx_texture_to_image(g->mlx, g->txt_enemy);
}

static void	clean_txt(t_slong *g)
{
	mlx_delete_texture(g->txt_player_right);
	mlx_delete_texture(g->txt_player_left);
	mlx_delete_texture(g->txt_player_frnt);
	mlx_delete_texture(g->txt_player_back);
	mlx_delete_texture(g->txt_enemy);
	mlx_delete_texture(g->txt_colection);
	mlx_delete_texture(g->txt_wall);
	mlx_delete_texture(g->txt_floor);
	mlx_delete_texture(g->txt_player_exit);
	mlx_delete_texture(g->txt_exit_close);
	mlx_delete_texture(g->txt_exit_open);
}

static int	img_to_window_error(t_slong *g, int x, int y, char c)
{
	if (c == '1')
		if (mlx_image_to_window(g->mlx, g->img_wall, x * 50, y * 50) < 0)
			return (0);
	if (c == '0')
		if (mlx_image_to_window(g->mlx, g->img_floor, x * 50, y * 50) < 0)
			return (0);
	if (c == 'P')
		if (mlx_image_to_window(g->mlx, g->img_player_frnt, x * 50, y * 50) < 0)
			return (0);
	if (c == 'E')
		if (mlx_image_to_window(g->mlx, g->img_exit_close, x * 50, y * 50) < 0)
			return (0);
	if (c == 'C')
		if (mlx_image_to_window(g->mlx, g->img_colection, x * 50, y * 50) < 0)
			return (0);
	if (c == 'S')
		if (mlx_image_to_window(g->mlx, g->img_enemy, x * 50, y * 50) < 0)
			return (0);
	return (1);
}

static int	img_to_window(t_slong *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->row)
	{
		x = -1;
		while (++x < g->col)
			if (!img_to_window_error(g, x, y, g->map[y][x]))
				return (0);
	}
	return (1);
}

int	draw_map(t_slong *g)
{
	png_to_txt_img(g);
	clean_txt(g);
	if (!img_error(g))
		return (0);
	if (!img_to_window(g))
		return (0);
	return (1);
}
