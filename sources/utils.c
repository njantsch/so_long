/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:14:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/21 16:02:38 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	terminate(t_game *g)
{
	mlx_delete_image(g->mlx, g->wall);
	mlx_delete_image(g->mlx, g->c);
	mlx_delete_image(g->mlx, g->exit);
	mlx_delete_image(g->mlx, g->mario);
	mlx_delete_image(g->mlx, g->back_g);
	mlx_delete_image(g->mlx, g->m);
	mlx_close_window(g->mlx);
	mlx_terminate(g->mlx);
	free_prev_alloc(g->map);
	free(g);
	exit(0);
}

void	free_prev_alloc(char **buff)
{
	size_t	j;

	j = 0;
	while (buff[j] != NULL)
	{
		free(buff[j]);
		j++;
	}
	free(buff);
}

// Checks if there are consecutive new lines inside the map
int	check_consec_nl(char *line_str)
{
	int	i;

	i = 0;
	while (line_str[i + 1])
	{
		if (line_str[i] == '\n' && line_str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	copy_lines(t_fill *fill, char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
		i++;
	fill->cpy = (char **)malloc((i + 1) * sizeof(char *));
	i = 0;
	while (lines[i])
	{
		fill->cpy[i] = ft_strdup(lines[i]);
		i++;
	}
	fill->cpy[i] = NULL;
}
