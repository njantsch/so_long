/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_check2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:50:21 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/12 18:29:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checks(char **lines, char *map)
{
	if (check_map_format(map) == 1)
		return (1);
	if (check_chars(lines) == 1)
		return (1);
	if (check_walls_a_others(lines) == 1)
		return (1);
	return (0);
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
