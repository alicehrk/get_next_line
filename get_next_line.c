/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:36:05 by harkim            #+#    #+#             */
/*   Updated: 2023/04/25 14:57:22 by harkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_newline_char(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_read_line(int fd, char **cache)
{
	char	read_buffer[BUFFER_SIZE + 1];
	int		read_size;

	while (ft_check_newline_char(*cache) == NULL)
	{
		read_size = read(fd, read_buffer, BUFFER_SIZE);
		if (read_size == -1)
			return (ft_free(cache));
		if (read_size == 0)
			return (*cache);
		read_buffer[read_size] = '\0';
		*cache = ft_strjoin(*cache, read_buffer, cache);
		if (!*cache)
			return (NULL);
	}
	return (*cache);
}

char	*ft_get_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		line[i] = buf[i];
	if (buf[i] == '\n')
	{
		line[i] = buf[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update(char **cache)
{
	char	*new_cache;
	char	*newline_position;

	newline_position = ft_check_newline_char(*cache);
	if (newline_position == NULL)
		return (ft_free(cache));
	new_cache = ft_strdup(newline_position + 1);
	if (!new_cache)
		return (ft_free(cache));
	ft_free(cache);
	return (new_cache);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cache;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	cache = ft_read_line(fd, &cache);
	if (!cache)
		return (NULL);
	line = ft_get_line(cache);
	if (!line)
		return (ft_free(&cache));
	cache = ft_update(&cache);
	return (line);
}
