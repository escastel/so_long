/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:11:38 by escastel          #+#    #+#             */
/*   Updated: 2023/10/13 16:24:28 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lek(void)
{
	system("leaks -q a.out");
}

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	init_struct(t_slong *game)
{
	game->map = NULL;
	game->map_cpy = NULL;
	game->p_map = 0;
	game->e_map = 0;
	game->c_map = 0;
	game->c_path = 0;
	game->e_path = 0;
}

int32_t	main(int argc, char **argv)
{
	t_slong			*game;

	game = ft_calloc(1, sizeof(t_slong));
	init_struct(game);
	save_map(game);
	check_extension(argv[1]);
	check_walls(game);
	check_content(game);
	check_rectangular_map(game);
	check_path(game->map_cpy, (t_point){game->h, game->w}, game->player_position, game);
	return (0);
}
