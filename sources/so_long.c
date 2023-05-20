/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:56:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/20 19:37:13 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	t_game	*g;

	if (argc == 1)
		return (ft_printf("Error\n not enough arguments\n"));
	else if (argc > 2)
		return (ft_printf("Error\n too many arguments\n"));
	map = valid_map_check(argv[1]);
	if (map == NULL)
		return (ft_printf("Error\nmap is not valid\n"));
	g = initialize_game(map);
	g->mlx = mlx_init(g->x, g->y, "so_long", false);
	if (!g->mlx)
		return (ft_printf("%s", mlx_strerror(mlx_errno)));
	get_coordinates(g);
	ft_get_textures(g);
	mlx_loop_hook(g->mlx, ft_hooks, g);
	mlx_loop(g->mlx);
	free_prev_alloc(map);
	terminate(g);
	return (EXIT_SUCCESS);
}
