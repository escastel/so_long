/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:11:38 by escastel          #+#    #+#             */
/*   Updated: 2023/10/13 14:57:25 by escastel         ###   ########.fr       */
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

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*text;
	mlx_image_t		*img;
	t_slong			*game;

	atexit(ft_lek);
	game = ft_calloc(1, sizeof(t_slong));
	init_struct(game);
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx = mlx_init(100, 100, "Meow", true);
	if (!mlx)
		ft_error();
	text = mlx_load_png("./imagenes/frente.png");
	if (!text)
		ft_error();
	img = mlx_texture_to_image(mlx, text);
	if (!img)
		ft_error();
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(text);
	mlx_terminate(mlx);
	return (0);
}
