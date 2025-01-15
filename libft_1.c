/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:26:33 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/14 20:03:21 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t  ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

char    *ft_strcpy(char *str, char *s1)
{
    int i;

    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    *ft_strcat(char *str, char *s2)
{
    int i;
    int j;

    i = 0;
    while (str[i])
        i++;
    j = 0;
    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}

char    *ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1));
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	str[len_s1 + len_s2 + 1] = '\0';
	// free (s2);
	return (str);
}