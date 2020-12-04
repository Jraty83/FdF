/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/12/04 15:51:27 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	For your mandatory part, you are allowed to use the following functions:
**	◦ open, read, write, close
**	◦ malloc, free
**	◦ perror, strerror
**	◦ exit
*/

#include "fdf.h"

/*
**	data_pixel_put(data, win, 50, 50, 212);		TEST - REMOVE
*/

int		deal_mouse(int button, int x, int y, void *param)
{
	ft_putnbr(3);
	return (0);
}

int		deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;
//	int		i = 0;	// FOR TESTING

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(3);
//	data->color = BLACK;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_error(0);
		if (!ft_reader(fd, data))
			return (0);
//		while (data->file[i])
//			printf("\033[32m%s\033[0m\n", data->file[i++]);
//		printf("number of lines: [%d]\tlength of each line: [%d]\n", data->nr_lines, data->line_length);
		data->mlx = mlx_init();
		data->win = mlx_new_window(data->mlx, 640, 360, "my Fdf");
		mlx_key_hook(data->win, deal_key, (void*)0);
		mlx_mouse_hook(data->win, deal_mouse, (void*)0);
		background(data);
		draw_line(data->mlx, data->win, 240, 100, 370, 20, RED);
		mlx_loop(data->mlx);
	}
	ft_putendl_fd("Usage : ./fdf <filename>", 2);
}

/*
**	how to pass parameters to data_pixel_put using data_key_hook's (void*)0 ?
**
**	use GNL to parse file 42.fdf
**
**	https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
**
**	https://qst0.github.io/ft_libgfx/man_data.html
**
**	data_pixel_put(data, win, 200, 200, RED);;
**
**	LAST COPY FT_ERROR TO OWN LIBFT !!
**
*/
