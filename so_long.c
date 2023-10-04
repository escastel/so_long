/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:11:38 by escastel          #+#    #+#             */
/*   Updated: 2023/10/04 15:39:13 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(t_slong *game)
{
	int		fd;
	char	*line;
	int		r; /*row*/
	int		c; /*column*/
	int		y;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	r = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		r++;
	}
	close(fd);
	game->map = ft_calloc((r + 1), sizeof(char *));
	if (!game->map)
		return ;
	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		c = (ft_strlen(line) - 1);
		if (line[c + 1] != '\n')
			c++;
		game->map[y] = ft_calloc(c, sizeof(char));
		if (!game->map)
			return ;
		ft_strlcpy(game->map[y], line, c);
		/* printf("%s", game->map[y]); */
		y++;
		free(line);
		line = get_next_line(fd);
	}
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
}

int32_t	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*text;
	mlx_image_t		*img;
	t_slong			*game;

	game = ft_calloc(1, sizeof(t_slong));
	init_struct(game);

	/* mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(1958, 1000, "Meow", true);
	if (!mlx)
		ft_error(); */
	/* text = mlx_load_png("./Gatopistola.png");
	if (!text)
		ft_error();
	img = mlx_texture_to_image(mlx, text);
	if (!img)
		ft_error();
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		ft_error(); */
	read_map(game);
	/* mlx_loop(mlx);
	 mlx_delete_image(mlx, img);
	mlx_delete_texture(text); */
	/* mlx_terminate(mlx); */
	return (0);
}
