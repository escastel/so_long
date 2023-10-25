/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:28:58 by escastel          #+#    #+#             */
/*   Updated: 2023/10/25 16:37:50 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_slong
{
	char			**map;
	char			**map_cpy;
	char			*str_count;
	t_point			p_pst;
	t_point			e_pst;
	int				fd;
	int				row;
	int				col;
	int				x;
	int				y;
	int				p_map;
	int				e_map;
	int				c_map;
	int				s_map;
	int				e_path;
	int				c_path;
	int				eat_c;
	int				count;
	mlx_t			*mlx;
	mlx_image_t		*img_count;
	mlx_texture_t	*txt_player_right;
	mlx_image_t		*img_player_right;
	mlx_texture_t	*txt_player_frnt;
	mlx_image_t		*img_player_frnt;
	mlx_texture_t	*txt_player_left;
	mlx_image_t		*img_player_left;
	mlx_texture_t	*txt_player_back;
	mlx_image_t		*img_player_back;
	mlx_texture_t	*txt_enemy;
	mlx_image_t		*img_enemy;
	mlx_texture_t	*txt_colection;
	mlx_image_t		*img_colection;
	mlx_texture_t	*txt_wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*txt_floor;
	mlx_image_t		*img_floor;
	mlx_texture_t	*txt_player_exit;
	mlx_image_t		*img_player_exit;
	mlx_texture_t	*txt_exit_close;
	mlx_image_t		*img_exit_close;
	mlx_texture_t	*txt_exit_open;
	mlx_image_t		*img_exit_open;
}	t_slong;

int		save_map(t_slong *game, char *argv);
int		check_content(t_slong *g);
int		check_map(t_slong *g, char *argv);
int		draw_map(t_slong *g);
int		img_error(t_slong *g);
void	keyhook(mlx_key_data_t keydata, void *param);
void	ft_clean(t_slong *g);
void	ft_close(void *param);

#endif