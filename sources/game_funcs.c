/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:28:06 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/17 19:30:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*initialize_game(char **map)
{
	t_game	*game;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->x = ft_strlen(map[0]) * DIMENS;
	while (map[i] != NULL)
		i++;
	game->y = i * DIMENS;
	game->map = map;
	return (game);
}
