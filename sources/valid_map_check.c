/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:48:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/21 14:08:48 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks if the map has the right format *.ber
int	check_map_format(char *map)
{
	int	i;

	i = ft_strlen(map);
	while (i >= 0)
	{
		if (map[i] == '.')
		{
			if (map[i + 1] == 'b' && map[i + 2] == 'e' && map[i + 3] == 'r')
				return (0);
			else
				return (1);
		}
		i--;
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
		i++;
	}
	return (0);
}

// Checks if there is 1 P, 1 E, and a minimum of 1 C
int	check_chars(char **lines)
{
	int	i;
	int	j;
	int	countc;
	int	count_p_e;

	i = -1;
	countc = 0;
	count_p_e = 0;
	while (lines[++i] != NULL)
	{
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] == 'E')
				count_p_e++;
			if (lines[i][j] == 'C')
				countc++;
			if (lines[i][j] == 'P')
				count_p_e++;
		}
	}
	if (count_p_e != 2 || countc < 1)
		return (1);
	return (0);
}

// checks if there are any other characters then the ones valid for the map
// and if the walls are valid.
int	check_walls_a_others(char **lines)
{
	int	x;
	int	y;

	y = -1;
	while (lines[++y] != NULL)
	{
		if (y > 0)
			if (ft_strlen(lines[y]) != ft_strlen(lines[0]))
				return (1);
		if (y == 0 || lines[y + 1] == NULL)
			if (check_first_a_last_wall(lines[y]) == 1)
				return (1);
		x = -1;
		while (lines[y][++x])
		{
			if (lines[y][0] != '1' ||
				(lines[y][x + 1] == '\0' && lines[y][x] != '1'))
				return (1);
			if (lines[y][x] != '0' && lines[y][x] != '1' && lines[y][x] != 'C'
				&& lines[y][x] != 'E' && lines[y][x] != 'P')
				return (1);
		}
	}
	return (0);
}

char	**valid_map_check(char *map)
{
	int		fd;
	char	*map_input;
	char	*get_line;
	char	**lines;

	map_input = ft_calloc(1, 1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (free(map_input), NULL);
	get_line = get_next_line(fd);
	while (get_line != NULL)
	{
		map_input = ft_strjoin_free(map_input, get_line);
		free(get_line);
		get_line = get_next_line(fd);
	}
	if (check_consec_nl(map_input))
		return (free(map_input), NULL);
	lines = ft_split(map_input, '\n');
	free(map_input);
	if (map_checks(lines, map) == 1)
		return (free_prev_alloc(lines), NULL);
	close(fd);
	return (lines);
}
