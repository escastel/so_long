/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:09:09 by escastel          #+#    #+#             */
/*   Updated: 2023/10/24 15:55:27 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	png_to_txt_img(t_slong *g)
{
	g->txt_player_right = mlx_load_png("./sprite/player_right.png");
	g->img_player_right = mlx_texture_to_image(g->mlx, g->txt_player_right);
	g->txt_player_frnt = mlx_load_png("./sprite/player_front.png");
	g->img_player_frnt = mlx_texture_to_image(g->mlx, g->txt_player_frnt);
	g->txt_player_left = mlx_load_png("./sprite/player_left.png");
	g->img_player_left = mlx_texture_to_image(g->mlx, g->txt_player_left);
	g->txt_player_back = mlx_load_png("./sprite/player_back.png");
	g->img_player_back = mlx_texture_to_image(g->mlx, g->txt_player_back);
	g->txt_colection = mlx_load_png("./sprite/colection.png");
	g->img_colection = mlx_texture_to_image(g->mlx, g->txt_colection);
	g->txt_wall = mlx_load_png("./sprite/wall.png");
	g->img_wall = mlx_texture_to_image(g->mlx, g->txt_wall);
	g->txt_floor = mlx_load_png("./sprite/floor.png");
	g->img_floor = mlx_texture_to_image(g->mlx, g->txt_floor);
	g->txt_player_exit = mlx_load_png("./sprite/player_exit.png");
	g->img_player_exit = mlx_texture_to_image(g->mlx, g->txt_player_exit);
	g->txt_exit_close = mlx_load_png("./sprite/exit_close.png");
	g->img_exit_close = mlx_texture_to_image(g->mlx, g->txt_exit_close);
	g->txt_exit_open = mlx_load_png("./sprite/exit_open.png");
	g->img_exit_open = mlx_texture_to_image(g->mlx, g->txt_exit_open);
}

static void	clean_txt(t_slong *g)
{
	mlx_delete_texture(g->txt_player_right);
	mlx_delete_texture(g->txt_player_left);
	mlx_delete_texture(g->txt_player_frnt);
	mlx_delete_texture(g->txt_player_back);
	mlx_delete_texture(g->txt_colection);
	mlx_delete_texture(g->txt_wall);
	mlx_delete_texture(g->txt_floor);
	mlx_delete_texture(g->txt_player_exit);
	mlx_delete_texture(g->txt_exit_close);
	mlx_delete_texture(g->txt_exit_open);
}

static void	img_to_window(t_slong *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < g->row)
	{
		x = -1;
		while (++x < g->col)
		{
			if (g->map[y][x] == '1')
				mlx_image_to_window(g->mlx, g->img_wall, x * 50, y * 50);
			if (g->map[y][x] == '0')
				mlx_image_to_window(g->mlx, g->img_floor, x * 50, y * 50);
			if (g->map[y][x] == 'P')
				mlx_image_to_window(g->mlx, g->img_player_frnt, x * 50, y * 50);
			if (g->map[y][x] == 'E')
				mlx_image_to_window(g->mlx, g->img_exit_close, x * 50, y * 50);
			if (g->map[y][x] == 'C')
				mlx_image_to_window(g->mlx, g->img_colection, x * 50, y * 50);
		}
	}
}

void	draw_map(t_slong *g)
{
	png_to_txt_img(g);
	clean_txt(g);
	img_to_window(g);
}
