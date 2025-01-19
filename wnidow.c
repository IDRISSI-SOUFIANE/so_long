/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wnidow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sidrissi <sidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 21:50:37 by sidrissi          #+#    #+#             */
/*   Updated: 2025/01/16 22:34:06 by sidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	call_window(void)
{
	void	*mlx_connection;
	void	*mlx_window;
    int     x;
    int     y;

	mlx_connection = mlx_init();
	mlx_window = mlx_new_window(mlx_connection, 500, 500, "My 1* window");
    x = 0;
    y = 0;
	while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            mlx_pixel_put(mlx_connection, mlx_window, x, y, 0xff0000);
            ++x;
        }
        ++y;
    }

//     for (int y = 0; y < HEIGHT; ++y)
//     {
//         for (int x = 0; x < WIDTH; ++x)
//         {
//             mlx_pixel_put(mlx_connection, mlx_window, x, y, 0xff0000);
            
//         }
//     }
    mlx_loop(mlx_connection);
}
