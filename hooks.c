/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:00:38 by escastel          #+#    #+#             */
/*   Updated: 2023/10/25 12:35:29 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	p_position2(t_slong *g, int y, int x, mlx_image_t *img);
static void	p_position3(t_slong *g, int y, int x, mlx_image_t *img);

static void	p_position1(t_slong *g, int y, int x, mlx_image_t *img)
{
	if (g->map[y][x] == '1')
		return ;
	if (g->map[y][x] == 'E')
	{
		g->count++;
		ft_printf("Numero de movimiento: %d\n", g->count);
		g->map[g->p_pst.y][g->p_pst.x] = '0';
		mlx_image_to_window(g->mlx, g->img_floor,
			g->p_pst.x * 50, g->p_pst.y * 50);
		if (g->eat_c != g->c_map)
			mlx_image_to_window(g->mlx, g->img_player_exit,
				g->e_pst.x * 50, g->e_pst.y * 50);
		else
			return (ft_close(g));
		g->p_pst.x = x;
		g->p_pst.y = y;
	}
	p_position2(g, y, x, img);
}

static void	p_position2(t_slong *g, int y, int x, mlx_image_t *img)
{
	if (g->map[y][x] == '0')
	{
		g->map[y][x] = 'P';
		mlx_image_to_window(g->mlx, img, x * 50, y * 50);
		if (g->map[g->p_pst.y][g->p_pst.x] == 'E')
			mlx_image_to_window(g->mlx, g->img_exit_close,
				g->e_pst.x * 50, g->e_pst.y * 50);
		else
		{
			g->map[g->p_pst.y][g->p_pst.x] = '0';
			mlx_image_to_window(g->mlx, g->img_floor,
				g->p_pst.x * 50, g->p_pst.y * 50);
		}
		g->p_pst.x = x;
		g->p_pst.y = y;
		g->count++;
		ft_printf("Numero de movimiento: %d\n", g->count);
	}
	p_position3(g, y, x, img);
}

static void	p_position3(t_slong *g, int y, int x, mlx_image_t *img)
{
	if (g->map[y][x] == 'C')
	{
		g->map[y][x] = 'P';
		mlx_image_to_window(g->mlx, img, x * 50, y * 50);
		if (g->map[g->p_pst.y][g->p_pst.x] == 'E')
		{
			mlx_image_to_window(g->mlx, g->img_exit_close,
				g->e_pst.x * 50, g->e_pst.y * 50);
		}
		else
		{
			g->map[g->p_pst.y][g->p_pst.x] = '0';
			mlx_image_to_window(g->mlx, g->img_floor,
				g->p_pst.x * 50, g->p_pst.y * 50);
		}
		g->eat_c++;
		if (g->eat_c == g->c_map)
			mlx_image_to_window(g->mlx, g->img_exit_open,
				g->e_pst.x * 50, g->e_pst.y * 50);
		g->p_pst.x = x;
		g->p_pst.y = y;
		g->count++;
		ft_printf("Numero de movimiento: %d\n", g->count);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_slong	*g;

	g = (t_slong *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		p_position1(g, g->p_pst.y - 1, g->p_pst.x, g->img_player_back);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		p_position1(g, g->p_pst.y + 1, g->p_pst.x, g->img_player_frnt);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		p_position1(g, g->p_pst.y, g->p_pst.x - 1, g->img_player_left);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		p_position1(g, g->p_pst.y, g->p_pst.x + 1, g->img_player_right);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		return (ft_close(g));
}
