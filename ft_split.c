/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:39:08 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/15 11:21:03 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free(char **res, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

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

char	*ft_strdup_split(char *str, int *preffix, char sp)
{
	char	*word;
	int		i;
	int		len_word;

	len_word = 0;
	i = *preffix;
	while (str[i] && is_newline(str[i], sp))
		i++;
	*preffix = i;
	while (str[i] && !(is_newline(str[i], sp)))
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
	i = 0;
	while (i < nb_word)
	{
		word_arr[i] = ft_strdup_split(res, &preffix, sp);
		if (!word_arr[i])
			return (ft_free(&res, i));
		i++;
	}
	word_arr[nb_word] = NULL;
	return (word_arr);
}
