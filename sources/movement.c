/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:24:43 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/20 19:31:11 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *g)
{
	g->ply_x = (g->mario->instances[0].x + 49) / DIMENS;
	g->ply_y = (g->mario->instances[0].y) / DIMENS;
	g->ply_x2 = g->mario->instances[0].x / DIMENS;
	g->ply_y2 = (g->mario->instances[0].y - 5) / DIMENS;
	if (g->map[g->ply_y][g->ply_x] == '1' \
	|| g->map[g->ply_y2][g->ply_x2] == '1')
		return (0);
	return (1);
}

int	move_down(t_game *g)
{
	g->ply_x = (g->mario->instances[0].x + 49) / DIMENS;
	g->ply_y = g->mario->instances[0].y / DIMENS;
	g->ply_x2 = g->mario->instances[0].x / DIMENS;
	g->ply_y2 = g->mario->instances[0].y / DIMENS;
	if (g->map[g->ply_y + 1][g->ply_x] == '1' \
	|| g->map[g->ply_y2 + 1][g->ply_x2] == '1')
		return (0);
	return (1);
}

int	move_left(t_game *g)
{
	g->ply_x = (g->mario->instances[0].x + 49) / DIMENS;
	g->ply_y = (g->mario->instances[0].y + 49) / DIMENS;
	g->ply_x2 = (g->mario->instances[0].x + 49) / DIMENS;
	g->ply_y2 = g->mario->instances[0].y / DIMENS;
	if (g->map[g->ply_y][g->ply_x - 1] == '1' \
	|| g->map[g->ply_y2][g->ply_x2 - 1] == '1')
		return (0);
	return (1);
}

int	move_right(t_game *g)
{
	g->ply_x = g->mario->instances[0].x / DIMENS;
	g->ply_y = g->mario->instances[0].y / DIMENS;
	g->ply_x2 = g->mario->instances[0].x / DIMENS;
	g->ply_y2 = (g->mario->instances[0].y + 49) / DIMENS;
	if (g->map[g->ply_y][g->ply_x + 1] == '1' \
	|| g->map[g->ply_y2][g->ply_x2 + 1] == '1')
		return (0);
	return (1);
}
