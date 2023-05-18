/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:14:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/16 13:29:46 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	terminate(t_game *game)
{
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->collectable);
	mlx_delete_image(game->mlx, game->exit);
	mlx_delete_image(game->mlx, game->standing_r);
	mlx_delete_image(game->mlx, game->background);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free(game);
	exit(0);
}
