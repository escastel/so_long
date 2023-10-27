/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:11:38 by escastel          #+#    #+#             */
/*   Updated: 2023/10/27 14:17:41 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	ft_lek(void)
{
	system("leaks -q solong");
} */

int	img_error(t_slong *g)
{
	if (!g->img_player_right || !g->img_player_left
		|| !g->img_player_frnt || !g->img_player_back
		|| !g->img_colection || !g->img_wall
		|| !g->img_floor || !g->img_player_exit
		|| !g->img_exit_close || !g->img_exit_open)
		return (ft_clean(g), 0);
	return (1);
}

void	ft_close(void *param)
{
	t_slong	*g;

	g = (t_slong *)param;
	mlx_close_window(g->mlx);
}

void	ft_clean(t_slong *g)
{
	int	y;

	if (g->map)
	{
		y = -1;
		while (g->map[++y])
			free(g->map[y]);
		free(g->map);
	}
	if (g->map_cpy)
	{
		y = -1;
		while (g->map_cpy[++y])
			free(g->map_cpy[y]);
		free(g->map_cpy);
	}
	free(g);
}

void	init_struct(t_slong *g)
{
	g->map = NULL;
	g->map_cpy = NULL;
	g->y = -1;
	g->p_map = 0;
	g->e_map = 0;
	g->c_map = 0;
	g->c_path = 0;
	g->e_path = 0;
	g->eat_c = 0;
	g->count = 0;
}

int32_t	main(int argc, char **argv)
{
	t_slong			*g;

	if (argc != 2)
	{
		return (ft_printf("Error\nSe requiere argumento\n"), 0);
	}
	/* atexit(ft_lek); */
	g = ft_calloc(1, sizeof(t_slong));
	init_struct(g);
	if (!save_map(g, argv[1]))
		return (0);
	if (!check_map(g, argv[1]))
		return (0);
	g->mlx = mlx_init((g->col - 1) * 50, g->row * 50, "So_long", false);
	if (!g->mlx)
		return (ft_clean(g), 1);
	if (!draw_map(g))
		return (0);
	mlx_key_hook(g->mlx, &keyhook, g);
	mlx_close_hook(g->mlx, &ft_close, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (ft_clean(g), 1);
}
