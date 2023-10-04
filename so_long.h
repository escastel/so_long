/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:07:54 by escastel          #+#    #+#             */
/*   Updated: 2023/10/04 15:09:16 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

typedef struct s_slong
{
	char	**map;
	char	**map_cpy;
}	t_slong;

void	read_map(t_slong *game);

#endif