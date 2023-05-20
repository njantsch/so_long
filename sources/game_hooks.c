/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 15:00:18 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/20 19:21:48 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook_move(t_game *g)
{
	if (mlx_is_key_down(g->mlx, MLX_KEY_W) \
	&& move_up(g) == 1)
		g->mario->instances[0].y -= 5;
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S) \
	&& move_down(g) == 1)
		g->mario->instances[0].y += 5;
	else if (mlx_is_key_down(g->mlx, MLX_KEY_A) \
	&& move_left(g) == 1)
		g->mario->instances[0].x -= 5;
	else if (mlx_is_key_down(g->mlx, MLX_KEY_D) \
	&& move_right(g) == 1)
		g->mario->instances[0].x += 5;
}

void	movecounter(t_game *g)
{
	int	x;
	int	y;

	x = g->x / 2;
	y = g->y - 35;
	if ((mlx_is_key_down(g->mlx, MLX_KEY_W) && move_up(g) == 1) || \
	(mlx_is_key_down(g->mlx, MLX_KEY_S) && move_down(g) == 1) || \
	(mlx_is_key_down(g->mlx, MLX_KEY_A) && move_left(g) == 1) || \
	(mlx_is_key_down(g->mlx, MLX_KEY_D) && move_right(g) == 1))
	{
		g->move++;
		if (g->put_count)
			mlx_delete_image(g->mlx, g->put_count);
		g->move_str = ft_itoa(g->move);
		g->put_count = mlx_put_string(g->mlx, g->move_str, x, y);
		free(g->move_str);
	}
}

void	ft_pickup(t_game *g)
{
	size_t	i;

	if (g->coll_count <= 0 && \
	g->ply_x == g->exit_x / DIMENS && \
	g->ply_y == g->exit_y / DIMENS)
	{
		ft_printf("\n\n\n\\**CONGRATS!**/\n\n\n");
		terminate(g);
	}
	i = 0;
	while (i < g->tmp && g->coll_count > 0)
	{
		if (g->ply_x == g->c->instances[i].x / DIMENS \
		&& g->ply_y == g->c->instances[i].y / DIMENS \
		&& g->c->instances[i].z != -100)
		{
			mlx_set_instance_depth(&g->c->instances[i], -100);
			g->coll_count--;
		}
		i++;
	}
}

void	ft_hooks(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		terminate(g);
	ft_hook_move(g);
	ft_pickup(g);
	movecounter(g);
}
