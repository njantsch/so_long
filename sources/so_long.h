/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:08:50 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/21 13:46:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libs.h"
# define DIMENS 50

typedef struct game
{
	mlx_t		*mlx;
	int			x;
	int			y;
	int			m_x;
	int			m_y;
	int			ply_x;
	int			ply_y;
	int			ply_x2;
	int			ply_y2;
	int			exit_x;
	int			exit_y;
	char		*move_str;
	size_t		tmp;
	size_t		*coll_x;
	size_t		*coll_y;
	size_t		c_x;
	size_t		c_y;
	size_t		coll_count;
	size_t		move;
	char		**map;
	mlx_image_t	*c;
	mlx_image_t	*wall;
	mlx_image_t	*back_g;
	mlx_image_t	*exit;
	mlx_image_t	*mario;
	mlx_image_t	*put_count;
	mlx_image_t	*m;
	xpm_t		*xpm_mario;
	xpm_t		*xpm_wall;
	xpm_t		*xpm_back_g;
	xpm_t		*xpm_coll;
	xpm_t		*xpm_exit;
}	t_game;

typedef struct fill
{
	char	wall;
	char	**cpy;
	int		begin_x;
	int		begin_y;
}	t_fill;

void	get_coordinates(t_game *game);
t_game	*initialize_game(char **map);
t_fill	*stru_init(char **lines);
char	**valid_map_check(char *map);
int		check_map_format(char *map);
int		check_walls_a_others(char **lines);
int		check_chars(char **lines);
int		check_first_a_last_wall(char *line);
void	free_prev_alloc(char **buff);
int		check_consec_nl(char *line_str);
int		map_checks(char **lines, char *map);
void	ft_hooks(void *param);
void	ft_hook_move(t_game *game);
void	ft_get_textures(t_game *game);
void	ft_print_walls_and_back(t_game *game);
void	movecounter(t_game *game);
void	terminate(t_game *game);
void	ft_coll(t_game *game);
void	ft_pickup(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
int		valid_path(t_fill *fill, char **lines);
void	flood_fill(t_fill *fill, int pos_x, int pos_y);
int		check_after_fill(char **lines);
void	copy_lines(t_fill *fill, char **lines);

#endif
