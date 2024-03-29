/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:12:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/08 14:18:00 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

void	ft_bzero_gnl(void *s, size_t n);
void	*ft_calloc_gnl(size_t count, size_t size);
size_t	len_gnl(const char *s);
char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char *s2);
int		check_new_line(char *buffer);

#endif
