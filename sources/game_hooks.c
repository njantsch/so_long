/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:00:18 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/12 17:43:19 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook_move(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		game->standing_r->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		game->standing_r->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		game->standing_r->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		game->standing_r->instances[0].x += 5;
}

void	ft_hook_others(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	ft_hook_move(game);
	ft_hook_others(game);
}
