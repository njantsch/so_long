/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:48:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/05 20:00:55 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if the map has the right format *.ber
int	check_map_format(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '.')
		{
			if (map[i + 1] == 'b' && map[i + 2] == 'e' && map[i + 3] == 'r')
				return (0);
			else
				return (1);
		}
		i++;
	}
	return (1);
}

// Checks if the first and last wall are valid and there are only 1's
int	check_first_a_last_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (1);
	}
	return (0);
}

// Checks if there is 1 P, 1 E, and minimum 1 C
int	check_chars(char **lines)
{
	int	i;
	int j;
	int countC;
	int countPandE;

	j = -1;
	i = -1;
	countC = 0;
	countPandE = 0;
	while (line[++i] != NULL)
	{
		while (line[i][++j])
		{
			if (line[i][j] == 'E')
				countPandE += 1;
			if (line[i][j] == 'C')
				countC += 1;
			if (line[i][j] == 'P')
				countPandE += 1;
		}
	}
	if (countPandE != 2 || countC < 1)
		return (1);
	return (0);
}


int check_map_walls(char **lines)
{
	int x;
	int y;

	y = 0;
	while (lines[y] != NULL)
	{
		if (y == 0 || lines[y + 1] == NULL)
			if (check_first_a_last_wall(lines[y]) == 1)
				return (1);
		x = 0;
		while (lines[y][x])
		{
			if (lines[y][0] != 1 || lines[y][x + 1] == '\n' && lines[y][x] != '1')
				return (1);
			if (lines[y][x] == 'E')

		}
	}
}

int	valid_map_check(char *map)
{
	int fd;
	int	i;
	char **lines;

	i = -1;
	if (check_map_format(map) == 1)
		return (1);
	fd = open(map);
	lines[++i] = get_next_line(fd);
	while (lines[i] != NULL)
		lines[++i] = get_next_line(fd);
	if (check_map_walls(lines) == 1)
		return (1);
	return (0);
}
