/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:56:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/11 17:32:11 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	char 	**map;
	t_game	*game;

	if (argc == 1)
		return (ft_printf("Error\n not enough arguments\n"));
	else if (argc > 2)
		return (ft_printf("Error\n too many arguments\n"));
	map = valid_map_check(argv[1]);
	if (map == NULL)
		return (ft_printf("Error\nmap is not valid\n"));
	game = initialize_game(map);
	game->mlx = mlx_init(game->x, game->y, "Bruh", false);
	if (!game->mlx)
		return (ft_printf("%s", mlx_strerror(mlx_errno)));
	ft_hook(game->mlx, ft_hook, game);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
