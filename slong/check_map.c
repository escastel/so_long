/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:26:48 by escastel          #+#    #+#             */
/*   Updated: 2023/10/27 14:51:51 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
Tomando en cuenta que return (0) es que se ha encontrado 
un fallo y que return (1) no :
*/

static int	check_extension_and_rectangular_map(t_slong *g, char *argv)
{
	int	i;
	int	cmp;
	int	y;
	int	x;
	int	flag;

	flag = 0;
	i = ft_strlen(argv) - 1;
	x = ft_strlen(g->map[0]);
	if (argv[i] == 'r' && argv[i - 1] == 'e'
		&& argv[i - 2] == 'b' && argv[i - 3] == '.')
		flag = 0;
	else
		flag = 1;
	y = -1;
	while (g->map[++y])
	{
		cmp = ft_strlen(g->map[y]);
		if (cmp != x)
			return (0);
	}
	if (!flag)
		return (1);
	return (0);
}

static int	check_walls(t_slong	*g)
{
	int	y;
	int	x;

	y = 1;
	while (g->map[y + 1])
	{
		x = ft_strlen(g->map[y]) - 1;
		if (g->map[y][0] != '1' || g->map[y][x] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (g->map[y][x] && g->map[0][x])
	{
		if (g->map[y][x] != '1' || g->map[0][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

static int	check_content(t_slong *g)
{
	while (g->map[++g->y])
	{
		g->x = -1;
		while (g->map[g->y][++g->x])
		{
			if (g->map[g->y][g->x] == 'P')
			{
				g->p_pst.x = g->x;
				g->p_pst.y = g->y;
				g->p_map++;
			}
			if (g->map[g->y][g->x] == 'E')
				g->e_map++;
			if (g->map[g->y][g->x] == 'C')
				g->c_map++;
			if (g->map[g->y][g->x] != '1' && g->map[g->y][g->x] != '0'
			&& g->map[g->y][g->x] != 'P' && g->map[g->y][g->x] != 'E'
			&& g->map[g->y][g->x] != 'C')
				return (0);
		}
	}
	if (g->p_map != 1 || g->e_map != 1 || g->c_map < 1)
		return (0);
	return (1);
}

static void	check_path(char **tab, t_point size, t_point cur, t_slong	*g)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (tab[cur.y][cur.x] == '1' || tab[cur.y][cur.x] == '*')
		return ;
	if (tab[cur.y][cur.x] == 'C')
		g->c_path++;
	if (tab[cur.y][cur.x] == 'E')
	{
		g->e_pst.x = cur.x;
		g->e_pst.y = cur.y;
		g->e_path++;
	}
	tab[cur.y][cur.x] = '*';
	check_path(tab, size, (t_point){cur.x - 1, cur.y}, g);
	check_path(tab, size, (t_point){cur.x + 1, cur.y}, g);
	check_path(tab, size, (t_point){cur.x, cur.y - 1}, g);
	check_path(tab, size, (t_point){cur.x, cur.y + 1}, g);
}

int	check_map(t_slong *g, char *argv)
{
	if (!check_extension_and_rectangular_map(g, argv))
	{
		ft_clean(g);
		return (ft_printf("Error\nMapa incorrecto\n"), 0);
	}
	if (!check_walls(g))
	{
		ft_clean(g);
		return (ft_printf("Error\nEl mapa no está rodeado de muros\n"), 0);
	}
	if (!check_content(g))
	{
		ft_clean(g);
		return (ft_printf("Error\nFallos en el contenido\n"), 0);
	}
	check_path(g->map_cpy, (t_point){(g->col - 1), g->row}, g->p_pst, g);
	if (g->c_path != g->c_map || g->e_path != g->e_map)
	{
		ft_clean(g);
		return (ft_printf("Error\nNo hay un camino correcto\n"), 0);
	}
	return (1);
}
