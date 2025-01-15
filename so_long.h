/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:16:08 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/14 23:12:06 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

char	*ft_strchr(char *s, char c);
char	*ft_left_over(char *line);
char	*read_file(int fd, char *left_over, char *buffer);
char	*extr_line(char *line);
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int     ft_strcmp(char *s1, char *s2);

int     is_newline(char c, char sp);
int     count_word(char *s);
char    *ft_strdup_split(char *preffix, char *res, char sp);
char	**ft_split(char *res, char sp);
#endif