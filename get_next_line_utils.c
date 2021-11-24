/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:23:43 by pnona             #+#    #+#             */
/*   Updated: 2021/11/23 20:28:28 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_strdup(const char *s1)
{
	char	*c;
	size_t	a;
	size_t	lench;

	lench = ft_strlen(s1);
	c = (char *)malloc(lench + 1);
	if (!c)
		return (NULL);
	a = 0;
	while (s1[a])
	{
		c[a] = s1[a];
		a++;
	}
	c[a] = '\0';
	return (c);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*answ;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	answ = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!answ)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		answ[j++] = s1[i++];
	i = 0;
	while (s2[i])
		answ[j++] = s2[i++];
	answ[j] = '\0';
	return (answ);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	slen = ft_strlen(src);
	i = 0;
	if (!dstsize)
		return (slen);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (slen);
}
