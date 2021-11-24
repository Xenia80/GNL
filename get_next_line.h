/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 14:26:13 by pnona             #+#    #+#             */
/*   Updated: 2021/11/24 21:10:25 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		check_end(char *text);
char	*create_line_without_n(char *text);
char	*begin_new_line(char *text);
char	*copy_text_from_buf(int fd, char *text, char *buf);

#endif