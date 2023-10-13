/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:00 by escastel          #+#    #+#             */
/*   Updated: 2023/10/13 15:21:31 by escastel         ###   ########.fr       */
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
}

static void	save_map_col(t_slong *game)
{
	int		fd;
	char	*line;
	int		col;
	int		y;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	y = 0;
	while (line)
	{
		col = ft_strlen(line);
		if (line[col - 1] != '\n')
				col++;
		game->map[y] = ft_calloc(col, sizeof(char));
		if (!game->map)
			return ;
		game->map_cpy[y] = ft_calloc(col, sizeof(char));
		if (!game->map_cpy)
			return ;
		ft_strlcpy(game->map[y], line, col);
		ft_strlcpy(game->map_cpy[y], line, col);
		y++;
		free(line);
		line = get_next_line(fd);
	}
}

void	save_map(t_slong *game)
{
	save_map_row(game);
	save_map_col(game);
}
