/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:00:18 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/18 17:47:12 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook_move(t_game *game)
{
		if (mlx_is_key_down(game->mlx, MLX_KEY_W) \
		&& move_up(game) == 1)
			game->standing_r->instances[0].y -= 5;
		else if (mlx_is_key_down(game->mlx, MLX_KEY_S) \
		&& move_down(game) == 1)
			game->standing_r->instances[0].y += 5;
		else if (mlx_is_key_down(game->mlx, MLX_KEY_A) \
		&& move_left(game) == 1)
			game->standing_r->instances[0].x -= 5;
		else if (mlx_is_key_down(game->mlx, MLX_KEY_D) \
		&& move_right(game) == 1)
			game->standing_r->instances[0].x += 5;
}

void	movecounter(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) || \
	mlx_is_key_down(game->mlx, MLX_KEY_S) || \
	mlx_is_key_down(game->mlx, MLX_KEY_A) || \
	mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		ft_printf("Movement: %d\n", game->move);
		game->move++;
	}
}

void	ft_pickup(t_game *game)
{
	size_t	i;

	if (game->coll_count <= 0 && \
	game->ply_x == game->exit_x / DIMENS && \
	game->ply_y == game->exit_y / DIMENS)
	{
		ft_printf("\n\n\n\\**CONGRATS!**/\n\n\n");
		terminate(game);
	}
	i = 0;
	while (i < game->tmp && game->coll_count > 0)
	{
		if (game->ply_x == game->collectable->instances[i].x / DIMENS \
		&& game->ply_y == game->collectable->instances[i].y / DIMENS \
		&& game->collectable->instances[i].z != -100)
		{
			mlx_set_instance_depth(&game->collectable->instances[i], -100);
			game->coll_count--;
		}
		i++;
	}
}

void	ft_hooks(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		terminate(game);
	ft_hook_move(game);
	ft_pickup(game);
	movecounter(game);
}
