/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:39:08 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/14 23:20:34 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_newline(char c, char sp)
{
	return (c == sp);
}

int	count_word(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] && !(is_newline(s[i], '\n')))
		{
			count++;
			while (s[i] && !(is_newline(s[i], '\n')))
				i++;
		}
		else
			i++;
	}
	return (count);
}

// char	*ft_strdup_split(char *preffix, char *res, char sp)
// {
// 	int		i;
// 	int		len_word;
// 	char	*word;

// 	i = *preffix;
// 	len_word = 0;
// 	while (res[i] && is_newline(res[i], sp))
// 		i++;
// 	*preffix = i;
// 	while (res[i] && !(is_newline(res[i], sp)))
// 	{
// 		len_word++;
// 		i++;
// 	}
// 	word = (char *)malloc((len_word + 1) * sizeof(char));
// 	i = 0;
// 	while (i < len_word)
// 		word[i++] = res[(*preffix)++];
// 	word[len_word] = '\0';
// 	return (word);
// }


char	*ft_strdup_split(char *str, int *preffix, char sp)
{
	char	*word;
	int		i;
	int		len_word;

	len_word = 0;
	i = *preffix;
	while (str[i] && is_space(str[i], sp))
		i++;
	*preffix = i;
	while (str[i] && !(is_space(str[i], sp)))
	{
		len_word++;
		i++;
	}
	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
		word[i++] = str[(*preffix)++];
	word[len_word] = '\0';
	return (word);
}

char	**ft_split(char *res, char sp)
{
	char	**word_arr;
	int		nb_word;
	int		i;
	int		preffix;

	preffix = 0;
	nb_word = count_word(res);
	word_arr = (char **)malloc((nb_word + 1) * sizeof(char *));
	if (!word_arr)
		return (NULL);
	while (i < nb_word)
	{
		word_arr[i] = ft_strdup_split(&preffix, res, sp);
		i++;
	}
	word_arr[nb_word] = NULL;
	return (word_arr);
}

int main()
{
    char **res;

    char    str[] = "hello\n word\n 133\n";
    res = ft_split(str, '\n');
	
	int i = 0;
	while (res[i])
	{
		printf(res[i]);
		free(res[i]);
		i++;
	}
}