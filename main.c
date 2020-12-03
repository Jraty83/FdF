/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/12/03 13:03:23 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* For your mandatory part, you are allowed to use the following functions:
	◦ open, read, write, close
	◦ malloc, free
	◦ perror, strerror
	◦ exit*/

#include "fdf.h"

int		deal_mouse(int button, int x, int y, void *param)
{
	ft_putnbr(3);
//	data_pixel_put(data, win, 50, 50, 212);											// TEST - REMOVE
	return (0);
}

int		deal_key(int key, void *param)
{
	ft_putchar('X');
//	data_pixel_put(data, win, 50, 50, 212);											// TEST - REMOVE
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	
	int		fd;
	char	*line;	// MOVE TO READER.C
	int		i;		// MOVE

	i = 0;
	if ((data = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (1);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putendl_fd("Invalid file", 2);
			// printf("No file %s\n", argv[1]);			// REMOVE PRINTF !!
			return (0);
		}
		// READ FUNCTION ? NO MORE OPEN OR GNL AFTER
		if (!map_validator(fd))
			return (0);
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("\033[32m%s\033[0m\n", line);
		}
		free(line);					// TEST - REMOVE
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, 640, 360, "my Fdf");
		mlx_key_hook(data->win, deal_key, (void*)0);
		mlx_mouse_hook(data->win, deal_mouse, (void*)0);
		background(data);
		// data_pixel_put(data, win, 200, 200, RED);;
		draw_line(data->mlx, data->win, 240, 100, 370, 20, RED);
		mlx_loop(data->mlx);
	}
	ft_putendl_fd("Usage : ./fdf <filename> [ case_size z_size ]", 2);
}

// how to pass parameters to data_pixel_put using data_key_hook's (void*)0 ?

// use GNL to parse file 42.fdf

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

// https://qst0.github.io/ft_libgfx/man_data.html
