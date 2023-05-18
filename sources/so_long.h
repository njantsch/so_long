/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:08:50 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/18 17:42:46 by njantsch         ###   ########.fr       */
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

typedef struct	game
{
	mlx_t		*mlx;
	int			x;
	int			y;
	int			ply_x;
	int			ply_y;
	int			ply_x2;
	int			ply_y2;
	int			exit_x;
	int			exit_y;
	size_t		tmp;
	size_t		*coll_x;
	size_t		*coll_y;
	size_t		c_x;
	size_t		c_y;
	size_t		coll_count;
	size_t		move;
	char		**map;
	mlx_image_t	*collectable;
	mlx_image_t	*wall;
	mlx_image_t	*background;
	mlx_image_t	*exit;
	mlx_image_t	*standing_r;
}	t_game;

void	get_coordinates(t_game *game);
t_game	*initialize_game(char **map);
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

#endif
