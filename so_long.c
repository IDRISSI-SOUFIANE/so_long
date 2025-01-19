/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:38:06 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/16 22:04:14 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f()
{
	system("leaks so_long");
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

char    is_pce10(char c)
{
    int    i;
    char *alpha;

    alpha = "PCE10";
    i = 0;
    while (alpha[i])
    {
        if (alpha[i] == c)
            return (c);
        i++;
    }
    return ('n');
}

int	process_char(char c, t_elements *elements)
{
	if (is_pce10(c) == 'P')
		elements->c_p++;
	else if (is_pce10(c) == 'C')
		elements->c_c++;
	else if (is_pce10(c) == 'E')
		elements->c_e++;
	else if (is_pce10(c) == '1' || is_pce10(c) == '0')
		elements->n = 1;
	else if (is_pce10(c) == 'n')
		return (0);
	// printf("%c\n", c);
	return (1);
}
int    check_the_element(char **res, int i, int j)
{
	t_elements elements;
	
	elements.c_p = 0;
	elements.c_c = 0;
	elements.c_e = 0;
	elements.n = 0;
	while (res[i])
	{
		j = 0;
		while (res[i][j])
		{
			if (!(process_char(res[i][j], &elements)))
				return (0);
			j++;
		}
		i++;
	}
	return (elements.c_p == 1 && elements.c_e == 1 && elements.c_c != 0);
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
		while (res[i][0] != '1' || res[i][columns - 1] != '1')
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
	return (ft_free(res_sp, i), free(res_check), 1);
}

int main(int ac, char **av)
{
	// atexit (f);
	if (!(check_argument(ac, av)))
		return (write (1, "The map is not valide\n", 22), 0);
	// else
	// 	printf("the map is valdie");
	call_window();	
		// check_map();
    return (0);
}
