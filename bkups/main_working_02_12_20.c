/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/12/02 14:39:57 by jraty            ###   ########.fr       */
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
//	mlx_pixel_put(mlx_ptr, win_ptr, 50, 50, 212);											// TEST - REMOVE
	return (0);
}

int		deal_key(int key, void *param)
{
	ft_putchar('X');
//	mlx_pixel_put(mlx_ptr, win_ptr, 50, 50, 212);											// TEST - REMOVE
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	int		fd;
	char	*line;
	int		i;

	i = 0;
	color = RED;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_putstr(strerror(2));
			// printf("No file %s\n", argv[1]);			// REMOVE PRINTF !!
			return (0);
		}
		if (!map_validator(fd))
			return (0);
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
			printf("\033[32m%s\033[0m\n", line);
		}
		free (line);					// TEST - REMOVE
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 640, 360, "my Fdf");
		mlx_key_hook(win_ptr, deal_key, (void*)0);
		mlx_mouse_hook(win_ptr, deal_mouse, (void*)0);
		background(mlx_ptr, win_ptr, YELLOW);
		// mlx_pixel_put(mlx_ptr, win_ptr, 200, 200, RED);;
		draw_line(mlx_ptr, win_ptr, 240, 100, 370, 20, ORANGE);
		mlx_loop(mlx_ptr);
	}
	ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
}

// how to pass parameters to mlx_pixel_put using mlx_key_hook's (void*)0 ?

// use GNL to parse file 42.fdf

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

// https://qst0.github.io/ft_libgfx/man_mlx.html
