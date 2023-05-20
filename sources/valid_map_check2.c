/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:50:21 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/20 19:36:00 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checks(char **lines, char *map)
{
	t_fill	*fill;

	if (check_map_format(map) == 1)
		return (1);
	if (check_chars(lines) == 1)
		return (1);
	if (check_walls_a_others(lines) == 1)
		return (1);
	fill = stru_init(lines);
	if (valid_path(fill, lines) == 1)
		return (1);
	return (0);
}

t_fill	*stru_init(char **lines)
{
	t_fill	*fill;
	int		i;
	int		j;

	i = 0;
	fill = malloc(sizeof(t_fill));
	fill->wall = '1';
	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] == 'P')
			{
				fill->begin_x = j;
				fill->begin_y = i;
				break ;
			}
		}
	}
	return (fill);
}

void	flood_fill(t_fill *fill, int pos_x, int pos_y)
{
	if (fill->cpy[pos_y][pos_x] == '1' || \
	fill->cpy[pos_y][pos_x] == '2')
		return ;
	fill->cpy[pos_y][pos_x] = '2';
	flood_fill(fill, pos_x + 1, pos_y);
	flood_fill(fill, pos_x - 1, pos_y);
	flood_fill(fill, pos_x, pos_y + 1);
	flood_fill(fill, pos_x, pos_y - 1);
	return ;
}

int	valid_path(t_fill *fill, char **lines)
{
	copy_lines(fill, lines);
	flood_fill(fill, fill->begin_x, fill->begin_y);
	if (check_after_fill(fill->cpy) == 1)
	{
		free_prev_alloc(fill->cpy);
		free(fill);
		return (1);
	}
	free_prev_alloc(fill->cpy);
	free(fill);
	return (0);
}

int	check_after_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			if (map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
