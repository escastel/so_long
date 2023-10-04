/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:00 by escastel          #+#    #+#             */
/*   Updated: 2023/10/04 15:45:39 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	reserve_row(int fd)
{
	char	*line;
	int		row;

	line = get_next_line(fd);
	row = 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		row++;
	}
	return (row);
}

void	read_map(t_slong *game)
{
	int		fd;
	char	*line;
	int		row;
	int		c;
	int		y;

	fd = open("map.ber", O_RDONLY);
	row = reserve_row(fd);
	close(fd);
	game->map = ft_calloc((row + 1), sizeof(char *));
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
		y++; /*pasa al siguiente puntero*/
		free(line);
		line = get_next_line(fd);
	}
}
