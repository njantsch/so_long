/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 13:24:43 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/18 15:13:45 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up(t_game *game)
{
	game->ply_x = (game->standing_r->instances[0].x + 49) / DIMENS;
	game->ply_y = (game->standing_r->instances[0].y) / DIMENS;
	game->ply_x2 = game->standing_r->instances[0].x / DIMENS;
	game->ply_y2 = (game->standing_r->instances[0].y - 5) / DIMENS;
	if (game->map[game->ply_y][game->ply_x] == '1' \
	|| game->map[game->ply_y2][game->ply_x2] == '1')
		return (0);
	return (1);
}

int	move_down(t_game *game)
{
	game->ply_x = (game->standing_r->instances[0].x + 49) / DIMENS;
	game->ply_y = game->standing_r->instances[0].y / DIMENS;
	game->ply_x2 = game->standing_r->instances[0].x / DIMENS;
	game->ply_y2 = game->standing_r->instances[0].y / DIMENS;
	if (game->map[game->ply_y + 1][game->ply_x] == '1' \
	|| game->map[game->ply_y2 + 1][game->ply_x2] == '1')
		return (0);
	return (1);
}

int	move_left(t_game *game)
{
	game->ply_x = (game->standing_r->instances[0].x + 49) / DIMENS;
	game->ply_y = (game->standing_r->instances[0].y + 49) / DIMENS;
	game->ply_x2 = (game->standing_r->instances[0].x + 49) / DIMENS;
	game->ply_y2 = game->standing_r->instances[0].y / DIMENS;
	if (game->map[game->ply_y][game->ply_x - 1] == '1' \
	|| game->map[game->ply_y2][game->ply_x2 - 1] == '1')
		return (0);
	return (1);
}

int	move_right(t_game *game)
{
	game->ply_x = game->standing_r->instances[0].x / DIMENS;
	game->ply_y = game->standing_r->instances[0].y / DIMENS;
	game->ply_x2 = game->standing_r->instances[0].x / DIMENS;
	game->ply_y2 = (game->standing_r->instances[0].y + 49) / DIMENS;
	if (game->map[game->ply_y][game->ply_x + 1] == '1' \
	|| game->map[game->ply_y2][game->ply_x2 + 1] == '1')
		return (0);
	return (1);
}
