/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:38:06 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/15 22:48:30 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f()
{
	system("leaks a.out");
}

char	*read_the_map(void)
{
	char	*res;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open("mab.ber", O_RDONLY, 0777);
	if (fd < 0)
		return (0);
	res = NULL;
	while ((line = get_next_line(fd)))
	{
		tmp = res;
		res = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		if (!res)
			return (close(fd), free(res), NULL);
	}
	return (close(fd), res);
}

int	check_the_element(char **res, int i, int j)
{
	int	c_P;
	int	c_C;
	int	c_E;
	
	c_P = 0;
	c_C = 0;
	c_E = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (res[i][j] == 'P')
				c_P++;
			if (res[i][j] == 'C')
				c_C++;
			if (res[i][j] == 'E')
				c_E++;
			j++;
		}
		i++;
	}
	printf("(c_P: %d) \t (c_C: %d) \t (c_E: %d)\n", c_P, c_C, c_E);
	if (c_P == 1 && c_E == 1 && c_C != 0) // you can add enemie (c_P >= 1 && c_P < 3)
		return (1);
	return (0);
}

int	check_the_walls(char **res, int line, int columns)
{
	int	i;
	int	j;

	j = 0;
	while (res[0][j])
	{
		if ((res[0][j] != '1') && (res[line - 1][j] != '1'))
			return (0);
		j++;
	}
	i = 0;
	while (res[i])
	{
		while (res[i][0] != '1' || res[i][columns - 1] != '1')//
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	if (!(check_the_element(res, i, j)))
		return (0);
	return (1);
}

int	check_the_map(char **res)
{
	int	i;
	int	j;
	int	columns;
	int	count;

	i = 0;
	columns = 0;
	count = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
			j++;
		if (columns != j)
		{
			columns = j;
			count++;
		}
		i++;
	}
	if ((count > 1) || (i >= j))
		return (0);
	if (!(check_the_walls(res, i, j)))
		return (0);
	return (1);
}

int	check_argument(int ac, char **av)
{
	char	*str;
	char	*res_check;
	char	**res_sp;
	int		i;

	if (ac > 2 || ac == 1)
		return (0);
	else if (ac == 2)
		if (!(av[1]))
			return (0);
	str = "mab.ber";
	if (!(ft_strcmp(str, av[1])))
		return (0);
	res_check = read_the_map();
	if (!(res_check))
		return (free(res_check), 0);
	res_sp = ft_split(res_check, '\n');
	i = 0;
	while (res_sp[i])
		i++;
	if (!(check_the_map(res_sp)))
		return (ft_free(res_sp, i), free(res_check), 0);
	return (free(res_sp), free(res_check), 1);//free(res_sp), 
}

int main(int ac, char **av)
{
	// atexit (f);
	if (!(check_argument(ac, av)))
		write (1, "The map is not valide\n", 22);
	else
		printf("valide");	
		// check_map();
    return (0);
}