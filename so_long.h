/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:07:54 by escastel          #+#    #+#             */
/*   Updated: 2023/10/13 15:22:31 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_slong
{
	char	**map;
	char	**map_cpy;
	int		h;
	int		w;
	int		p_map;
	int		e_map;
	int		c_map;
	int		e_path;
	int		c_path;
}	t_slong;

void	save_map(t_slong *game);
int		check_extension(char *arg);
int		check_walls(t_slong	*game);
int		check_content(t_slong *game);
int		check_rectangular_map(t_slong *game);
void	check_path(char **tab, t_point size, t_point cur, t_slong	*game);

#endif