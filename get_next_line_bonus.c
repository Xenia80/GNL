/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:33:40 by pnona             #+#    #+#             */
/*   Updated: 2021/11/27 15:45:48 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int	check_end(char *text)
{
	int	i;

	i = 0;
	if (!text)
		return (0);
	while (text[i])
	{
		if (text[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*create_line_without_n(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, text, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*begin_new_line(char *text)
{
	char	*remainder;
	int		i;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\0')
	{
		free (text);
		return (NULL);
	}
	remainder = (char *)malloc(sizeof(char) * (ft_strlen(text) - i + 1));
	if (!remainder)
	{
		free (text);
		return (NULL);
	}
	ft_strlcpy(remainder, text + i + 1, ft_strlen(text) - i + 1);
	free (text);
	return (remainder);
}

char	*copy_text_from_buf(int fd, char *text, char *buf)
{
	int		if_read;
	char	*tmp;

	if_read = 1;
	while (if_read != 0 && !check_end(text))
	{
		if_read = read(fd, buf, BUFFER_SIZE);
		if (if_read < 0)
			return (NULL);
		buf[if_read] = '\0';
		if (!text)
			text = ft_strdup("");
		if (!text)
			return (NULL);
		tmp = text;
		text = ft_strjoin(tmp, buf);
		if (!text)
			return (NULL);
		free(tmp);
	}
	return (text);
}

char	*get_next_line(int fd)
{
	char		*ret_line;
	char		*buf;
	static char	*text[FD_MAX_COUNT] = {0};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		free (buf);
		return (NULL);
	}
	text[fd] = copy_text_from_buf(fd, text[fd], buf);
	free (buf);
	if (!text[fd])
		return (NULL);
	ret_line = create_line_without_n(text[fd]);
	text[fd] = begin_new_line(text[fd]);
	return (ret_line);
}

int	main(void)
{
	int		fd_1, fd_2;
	char	*line;

	fd_1 = open("text.txt", O_RDONLY);
	fd_2 = open("text1.txt", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd_1);
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd_2);
		printf("%s\n", line);
		free(line);
	}
	close(fd_1);
	close(fd_2);
	return (0);
}
