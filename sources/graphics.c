/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:06:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/18 17:43:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coordinates(t_game *game)
{
	size_t		i;
	size_t		j;

	i = 0;
	while(game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->ply_x = j * DIMENS;
				game->ply_y = i * DIMENS;
			}
			else if (game->map[i][j] == 'E')
			{
				game->exit_x = j * DIMENS;
				game->exit_y = i * DIMENS;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_textures(t_game *game)
{
	xpm_t	*xpm_standing_r;
	xpm_t	*xpm_wall;
	xpm_t	*xpm_background;
	xpm_t	*xpm_collectable;
	xpm_t	*xpm_exit;

	xpm_wall = mlx_load_xpm42("./textures/Wall.xpm42");
	game->wall = mlx_texture_to_image(game->mlx, &xpm_wall->texture);
	xpm_standing_r = mlx_load_xpm42("./textures/Mario.xpm42");
	game->standing_r = mlx_texture_to_image(game->mlx, &xpm_standing_r->texture);
	xpm_collectable = mlx_load_xpm42("./textures/Collectable.xpm42");
	game->collectable = mlx_texture_to_image(game->mlx, &xpm_collectable->texture);
	xpm_background = mlx_load_xpm42("./textures/Background.xpm42");
	game->background = mlx_texture_to_image(game->mlx, &xpm_background->texture);
	xpm_exit = mlx_load_xpm42("./textures/Exit.xpm42");
	game->exit = mlx_texture_to_image(game->mlx, &xpm_exit->texture);
	ft_print_walls_and_back(game);
	ft_coll(game);
	game->tmp = game->coll_count;
	mlx_image_to_window(game->mlx, game->exit, game->exit_x, game->exit_y);
	mlx_image_to_window(game->mlx, game->standing_r, game->ply_x, game->ply_y);
}

void	ft_coll(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->coll_count = 0;
	game->c_y = 0;
	while (game->map[++i])
	{
		j = -1;

		game->c_x = 0;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'C')
			{
				mlx_image_to_window(game->mlx, game->collectable, game->c_x, game->c_y);
				game->coll_count += 1;
			}
			game->c_x += DIMENS;
		}
		game->c_y += DIMENS;
	}
}

void	ft_print_walls_and_back(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (game->map[i])
	{
		j = 0;
		x = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1')
				mlx_image_to_window(game->mlx, game->background, x, y);
			if (game->map[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, x, y);
			x += 50;
			j++;
		}
		i++;
		y += 50;
	}
}
