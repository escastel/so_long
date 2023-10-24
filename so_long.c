/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:11:38 by escastel          #+#    #+#             */
/*   Updated: 2023/10/24 15:24:50 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lek(void)
{
	system("leaks -q a.out");
}

void	ft_close(void *param)
{
	t_slong	*g;

	g = (t_slong *)param;
	ft_clean(g);
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
}

int32_t	main(int argc, char **argv)
{
	t_slong			*g;

	if (argc != 2)
	{
		return (ft_printf("Error\nSe requiere argumento"), 0);
	}
	atexit(ft_lek);
	g = ft_calloc(1, sizeof(t_slong));
	init_struct(g);
	if (!save_map(g, argv[1]))
		return (0);
	if (!check_map(g, argv[1]))
		return (0);
	g->mlx = mlx_init((g->col - 1) * 50, g->row * 50, "Test", false);
	draw_map(g);
	mlx_key_hook(g->mlx, &keyhook, g);
	mlx_close_hook(g->mlx, ft_close, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (0);
}
