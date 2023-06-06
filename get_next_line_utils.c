/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harkim <harkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:47:15 by harkim            #+#    #+#             */
/*   Updated: 2023/04/23 21:25:41 by harkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **p)
{
	if (*p)
		free(*p);
	*p = 0;
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		s1_len;
	char	*new_str;

	i = 0;
	s1_len = ft_strlen(s1);
	new_str = malloc(s1_len + 1);
	if (!new_str)
		return (0);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (!src && dst)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dstsize && s[i] != '\0')
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, char **p)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
	{
		free(*p);
		return (NULL);
	}
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcpy(str + len1, s2, len2 + 1);
	free(*p);
	return (str);
}
