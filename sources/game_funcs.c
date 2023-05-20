/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:28:06 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/20 18:27:10 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*initialize_game(char **map)
{
	t_game	*g;
	int		i;

	i = 0;
	g = malloc(sizeof(t_game));
	g->x = ft_strlen(map[0]) * DIMENS;
	while (map[i] != NULL)
		i++;
	g->y = i * DIMENS;
	g->move = 0;
	g->m_x = g->x / 2 - 100;
	g->m_y = g->y - 35;
	g->map = map;
	return (g);
}
