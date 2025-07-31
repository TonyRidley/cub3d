/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tridley <tridley@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 16:40:52 by tridley           #+#    #+#             */
/*   Updated: 2025/01/07 16:46:44 by tridley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*get_next_line(int fd);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*read_first_line(int fd, char *text);
char	*ft_get_line(char *text);
char	*clean_first_line(char *text);

#endif