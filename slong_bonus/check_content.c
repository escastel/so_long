/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_content.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:23:46 by escastel          #+#    #+#             */
/*   Updated: 2023/10/25 16:31:24 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_content1(t_slong *g)
{
	g->y = -1;
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
			if (g->map[g->y][g->x] != '1' && g->map[g->y][g->x] != '0'
			&& g->map[g->y][g->x] != 'P' && g->map[g->y][g->x] != 'E'
			&& g->map[g->y][g->x] != 'C' && g->map[g->y][g->x] != 'S')
				return (0);
		}
	}
	if (g->p_map != 1 || g->e_map != 1)
		return (0);
	return (1);
}

int	check_content(t_slong *g)
{
	g->y = -1;
	while (g->map[++g->y])
	{
		g->x = -1;
		while (g->map[g->y][++g->x])
		{
			if (g->map[g->y][g->x] == 'C')
				g->c_map++;
			if (g->map[g->y][g->x] == 'S')
				g->s_map++;
			if (g->map[g->y][g->x] != '1' && g->map[g->y][g->x] != '0'
			&& g->map[g->y][g->x] != 'P' && g->map[g->y][g->x] != 'E'
			&& g->map[g->y][g->x] != 'C' && g->map[g->y][g->x] != 'S')
				return (0);
		}
	}
	if (g->c_map < 1 || g->s_map < 1)
		return (0);
	if (!check_content1(g))
		return (0);
	return (1);
}
