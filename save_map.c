/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:00 by escastel          #+#    #+#             */
/*   Updated: 2023/10/13 16:16:54 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	save_map_row(t_slong *game)
{
	int		fd;
	char	*line;
	int		row;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (free(line));
	row = 0;
	while (line)
	{
		row++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map = ft_calloc((row + 1), sizeof(char *));
	if (!game->map)
		return ;
	game->map_cpy = ft_calloc((row + 1), sizeof(char *));
	if (!game->map_cpy)
		return ;
	game->h = row;
	printf("Lineas de mi mapa: %d", game->h);
}

static void	save_map_col(t_slong *game)
{
	int		fd;
	char	*line;
	int		y;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		game->w = ft_strlen(line);
		if (line[game->w - 1] != '\n')
				game->w++;
		game->map[y] = ft_calloc(game->w, sizeof(char));
		if (!game->map)
			return ;
		game->map_cpy[y] = ft_calloc(game->w, sizeof(char));
		if (!game->map_cpy)
			return ;
		ft_strlcpy(game->map[y], line, game->w);
		ft_strlcpy(game->map_cpy[y], line, game->w);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	printf("Columnas de mi mapa: %d", game->w);
}

void	save_map(t_slong *game)
{
	save_map_row(game);
	save_map_col(game);
}
