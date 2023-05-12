/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:08:50 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/12 18:46:06 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libs/libs.h"

typedef struct	game
{
	mlx_t		*mlx;
	int			x;
	int			y;
	mlx_image_t	*collectable;
	mlx_image_t	*background;
	mlx_image_t	*standing_r;
}	t_game;

typedef struct	coords
{
	int	ply_x;
	int	ply_y;
	int	coin_x;
	int	coin_y;
}	t_coords;

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
void	ft_get_textures(t_game *game);
void	ft_hook_others(t_game *game);

#endif
