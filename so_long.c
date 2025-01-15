/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 21:38:06 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/14 23:10:02 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_map()
// {
// 	char	*line;
// 	int		fd;
// 	fd = open("mab.ber", O_RDONLY, 0777);
// 	while ((line == get_next_line(fd)))
// 	{
		
// 	}
// }

char	*check_the_map(void)
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
		if (tmp)
			tmp = res;
		else
			tmp = "";
		res = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		if (!res)
			return (close(fd), free(res), NULL);
	}
	return (close(fd), res);
}


int	check_argument(int ac, char **av)
{
	char	*str;
	char	*res;
	char	**res_sp;

	if (ac > 2 || ac == 1)
		return (0);
	else if (ac == 2)
		if (!(av[1]))
			return (0); // exit ()
	str = "mab.ber";
	if (!(ft_strcmp(str, av[1])))
		return (0);
	res = check_the_map();
	if (!(res))
		return (free(res), 0); 
	res_sp = ft_split(res, '\n');
	return (free(res), 1);
}

int main(int ac, char **av)
{
	if (check_argument(ac, av))
		// check_map();
    return (0);
}