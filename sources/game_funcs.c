/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:06:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/12 18:49:53 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*initialize_game(char **map)
{
	t_game	*game;
	int		i;

	i = 0;
	game = malloc(sizeof(t_game));
	game->x = ft_strlen(map[0]) * 60;
	while (map[i] != NULL)
		i++;
	game->y = i * 60;
	return (game);
}

t_coords	*get_coordinates(char **map)
{
	t_coords	*coords;

	
}

void	ft_get_textures(t_game *game)
{
	mlx_texture_t	*tex_standing_r;
	mlx_texture_t	*tex_collectable;
	mlx_texture_t	*tex_background;

	tex_standing_r = mlx_load_png("./textures/Standing_right.png");
	game->standing_r = mlx_texture_to_image(game->mlx, tex_standing_r);
	tex_collectable = mlx_load_png("./textures/Collectable.png");
	game->collectable = mlx_texture_to_image(game->mlx, tex_collectable);
	tex_background = mlx_load_png("./textures/Background.png");
	game->background = mlx_texture_to_image(game->mlx, tex_background);
	mlx_image_to_window(game->mlx, game->background, 0, 0);
	mlx_image_to_window(game->mlx, game->standing_r, 35, 37);
}
