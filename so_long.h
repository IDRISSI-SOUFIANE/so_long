/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:16:08 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/16 22:25:42 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif

#define WIDTH 500
#define HEIGHT 500

typedef struct n_element
{
    int c_p;
    int c_c;
    int c_e;
    int n;
} t_elements;

//get_nex_line
char	*ft_strchr(char *s, char c);
char	*ft_left_over(char *line);
char	*read_file(int fd, char *left_over, char *buffer);
char	*extr_line(char *line);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);

// libft
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int     ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);

//ft_split
int     is_newline(char c, char sp);
int     count_word(char *s);
char	*ft_strdup_split(char *str, int *preffix, char sp);
char	**ft_split(char *res, char sp);
void    *ft_free(char **res, int count);
// so_long
char    *read_the_map(void);
char	is_PCE1(char c);
int     check_the_element(char **res, int i, int j);
int     check_the_walls(char **res, int line, int columns);
int     check_the_map(char **res);
int     check_argument(int ac, char **av);
void    call_window(void);
#endif