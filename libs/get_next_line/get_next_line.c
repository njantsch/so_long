/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:57:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/05/05 17:22:03 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buff_trim(char *buffer)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new = ft_calloc((ft_strlen(buffer) + 1) - i, sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		new[j++] = buffer[i++];
	new[j] = '\0';
	free(buffer);
	return (new);
}

static char	*get_line(char *buffer)
{
	int		j;
	int		i;
	char	*new;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		new[j++] = buffer[i++];
	if (buffer[i] == '\n')
		new[j++] = buffer[i++];
	return (new);
}

char	*read_loop(int fd, char *buffer)
{
	char	*new_buff;
	int		bytes_read;

	new_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_buff)
		return (NULL);
	bytes_read = 1;
	while (check_new_line(buffer) == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, new_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_buff);
			free(buffer);
			return (NULL);
		}
		new_buff[bytes_read] = '\0';
		buffer = ft_strjoin_free(buffer, new_buff);
	}
	free(new_buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_loop(fd, buffer);
	if (!buffer)
		return (free(buffer), NULL);
	line = get_line(buffer);
	buffer = buff_trim(buffer);
	return (line);
}
