/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:56:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/05 19:23:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		return (ft_printf("Error\n not enough arguments\n"));
	else if (argc > 2)
		return (ft_printf("Error\n too many arguments\n"));
	if (valid_map_check(argv[1]) == 1)
		return (ft_printf("Error\n map is not valid\n"));
}
