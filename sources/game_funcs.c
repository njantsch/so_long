/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:06:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/11 17:53:17 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*initialize_game(char **map)
{
	t_game	*game;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->x = ft_strlen(map[0]) * 50;
	while (map[i] != NULL)
		i++;
	game->y = i * 50;
	return (game);
}

void	ft_get_textures(t_game game, char **)

void	ft_hook(mlx_key_data_t keydata)
{
	if ()

}

