/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:26:48 by escastel          #+#    #+#             */
/*   Updated: 2023/10/13 15:06:31 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Tomando en cuenta que return (0) es que se ha encontrado 
un fallo y que return (1) no :
*/

int	check_extension(char *arg)
{
	int	i;

	i = ft_strlen(arg) - 1;
	if (arg[i] == 'r')
	{
		if (arg[--i] == 'e')
		{
			if (arg[--i] == 'b')
			{
				if (arg[--i] == '.')
					return (1);
			}
		}
	}
	return (0);
}

int	check_walls(t_slong	*game)
{
	int	y;
	int	x;

	y = 1;
	while (game->map[y + 1])
	{
		x = ft_strlen(game->map[y]);
		if (game->map[y][0] != '1' || game->map[y][x] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (game->map[y][x] && game->map[0][x])
	{
		if (game->map[y][x] != '1' || game->map[0][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_content(t_slong *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P')
				game->p_map++;
			if (game->map[y][x] == 'E')
				game->e_map++;
			if (game->map[y][x] == 'C')
				game->c_map++;
			if (game->map[y][x] != '1' && game->map[y][x] != '0'
			&& game->map[y][x] != 'P' && game->map[y][x] != 'E'
			&& game->map[y][x] != 'C')
				return (0);
		}
	}
	if (game->p_map != 1 || game->e_map != 1 || game->c_map < 1)
		return (0);
	return (1);
}

int	check_rectangular_map(t_slong *game)
{
	int	y;
	int	x;
	int	cmp;

	x = ft_strlen(game->map[0]);
	y = 1;
	while (game->map[y])
	{
		cmp = ft_strlen(game->map[y]);
		if (cmp != x)
			return (0);
		y++;
	}
	return (1);
}

void	check_path(char **tab, t_point size, t_point cur, t_slong	*game)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == '*')
		return ;
	if (tab[cur.y][cur.x] == 'C')
		game->c_path++;
	if (tab[cur.y][cur.x] == 'E')
		game->e_path++;
	tab[cur.y][cur.x] = '*';
	check_path(tab, size, (t_point){cur.x - 1, cur.y}, game);
	check_path(tab, size, (t_point){cur.x + 1, cur.y}, game);
	check_path(tab, size, (t_point){cur.x, cur.y - 1}, game);
	check_path(tab, size, (t_point){cur.x, cur.y + 1}, game);
}
