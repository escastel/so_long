/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:33:00 by escastel          #+#    #+#             */
/*   Updated: 2023/10/27 14:48:46 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	save_map_row(t_slong *g, char *argv)
{
	char	*line;

	g->fd = open(argv, O_RDONLY);
	line = get_next_line(g->fd);
	if (!line)
		return (ft_clean(g), ft_printf("Error\nEl archivo no es válido\n"), 0);
	g->row = 0;
	while (line)
	{
		g->row++;
		free(line);
		line = get_next_line(g->fd);
	}
	close(g->fd);
	g->map = ft_calloc((g->row + 1), sizeof(char *));
	if (!g->map)
		return (ft_clean(g), 0);
	g->map_cpy = ft_calloc((g->row + 1), sizeof(char *));
	if (!g->map_cpy)
		return (ft_clean(g), 0);
	return (1);
}

static int	save_map_col(t_slong *g, char *argv)
{
	char	*line;
	int		y;

	g->fd = open(argv, O_RDONLY);
	line = get_next_line(g->fd);
	y = 0;
	while (line)
	{
		g->col = ft_strlen(line);
		if (line[g->col - 1] != '\n')
			g->col++;
		g->map[y] = ft_calloc(g->col, sizeof(char));
		if (!g->map)
			return (ft_clean(g), 0);
		g->map_cpy[y] = ft_calloc(g->col, sizeof(char));
		if (!g->map_cpy)
			return (ft_clean(g), 0);
		ft_strlcpy(g->map[y], line, g->col);
		ft_strlcpy(g->map_cpy[y], line, g->col);
		y++;
		free(line);
		line = get_next_line(g->fd);
	}
	close(g->fd);
	return (1);
}

int	save_map(t_slong *g, char *argv)
{
	if (!save_map_row(g, argv))
		return (0);
	if (!save_map_col(g, argv))
		return (0);
	return (1);
}
