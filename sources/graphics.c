/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:06:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/21 13:50:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coordinates(t_game *g)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->ply_x = j * DIMENS;
				g->ply_y = i * DIMENS;
			}
			else if (g->map[i][j] == 'E')
			{
				g->exit_x = j * DIMENS;
				g->exit_y = i * DIMENS;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_textures(t_game *g)
{
	g->xpm_wall = mlx_load_xpm42("./textures/Wall.xpm42");
	g->wall = mlx_texture_to_image(g->mlx, &g->xpm_wall->texture);
	mlx_delete_xpm42(g->xpm_wall);
	g->xpm_mario = mlx_load_xpm42("./textures/Mario.xpm42");
	g->mario = mlx_texture_to_image(g->mlx, &g->xpm_mario->texture);
	mlx_delete_xpm42(g->xpm_mario);
	g->xpm_coll = mlx_load_xpm42("./textures/Collectable.xpm42");
	g->c = mlx_texture_to_image(g->mlx, &g->xpm_coll->texture);
	mlx_delete_xpm42(g->xpm_coll);
	g->xpm_back_g = mlx_load_xpm42("./textures/Background.xpm42");
	g->back_g = mlx_texture_to_image(g->mlx, &g->xpm_back_g->texture);
	mlx_delete_xpm42(g->xpm_back_g);
	g->xpm_exit = mlx_load_xpm42("./textures/Exit.xpm42");
	g->exit = mlx_texture_to_image(g->mlx, &g->xpm_exit->texture);
	mlx_delete_xpm42(g->xpm_exit);
	ft_print_walls_and_back(g);
	ft_coll(g);
	g->tmp = g->coll_count;
	mlx_image_to_window(g->mlx, g->exit, g->exit_x, g->exit_y);
	mlx_image_to_window(g->mlx, g->mario, g->ply_x, g->ply_y);
	g->m = mlx_put_string(g->mlx, "Movement: ", g->m_x, g->m_y);
}

void	ft_coll(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	g->coll_count = 0;
	g->c_y = 0;
	while (g->map[++i])
	{
		j = -1;
		g->c_x = 0;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'C')
			{
				mlx_image_to_window(g->mlx, g->c, g->c_x, g->c_y);
				g->coll_count += 1;
			}
			g->c_x += DIMENS;
		}
		g->c_y += DIMENS;
	}
}

void	ft_print_walls_and_back(t_game *g)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (g->map[i])
	{
		j = 0;
		x = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] != '1')
				mlx_image_to_window(g->mlx, g->back_g, x, y);
			if (g->map[i][j] == '1')
				mlx_image_to_window(g->mlx, g->wall, x, y);
			x += 50;
			j++;
		}
		i++;
		y += 50;
	}
}
