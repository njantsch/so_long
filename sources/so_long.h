/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:08:50 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/08 19:51:56 by njantsch         ###   ########.fr       */
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
	int		width;
	int		height;

}	t_game;
int		valid_map_check(char *map);
int		check_map_format(char *map);
int		check_walls_a_others(char **lines);
int		check_chars(char **lines);
int		check_first_a_last_wall(char *line);
void	free_prev_alloc(char **buff);
int		check_consec_nl(char *line_str);
int		map_checks(char **lines, char *map);

#endif
