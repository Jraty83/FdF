/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/12/11 01:08:41 by jraty            ###   ########.fr       */
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

void	init_session(t_data *data)
{
	data->mlx = mlx_init();
	data->MAP_HEIGHT = 600;
	data->MAP_WIDTH = 1000; // 1067
	data->LEFT_MARGIN = 10;
	data->RIGHT_MARGIN = (data->MAP_WIDTH - 200);
	data->win = mlx_new_window(data->mlx, data->MAP_WIDTH, data->MAP_HEIGHT, "my Fdf");
	data->bg_color = BLACK;
	data->line_color = GREEN;
	data->x_offset = 10;
	data->y_offset = 30;
	data->x_start = data->x_offset;
	data->y_start = data->y_offset;
//	data->x1 = data->x_start;	// MOVED TO DRAW
//	data->y1 = data->y_start;
	data->zoom_offset = 20;
	data->zoom = data->zoom_offset;
	data->move_offset = 20;
	data->move = data->move_offset;
}

int		main(int argc, char **argv)
{
	t_data	*data;
	int		fd;
//	int		i = 0;	// FOR TESTING

	if (!(data = (t_data *)malloc(sizeof(t_data))))
		ft_error(3);
	if (argc == 2)
	{
		init_session(data);
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			ft_error(0);
		if (!ft_reader(fd, data))
			return (0);
		parse_int(data);
//		while (data->file[i])
//			printf("\033[32m%s\033[0m\n", data->file[i++]);
//		printf("\nnumber of lines: [%d]\tlength of each line: [%d]\n", data->nr_lines, data->line_length);
//		while (data->height[i])
//			printf("\033[32m%d\033[0m\n", data->height[i++]);
		draw(data);
		mlx_key_hook(data->win, deal_key, data);
		mlx_mouse_hook(data->win, deal_mouse, data);
//		system("leaks fdf"); // CHECK FOR LEAKS
		mlx_loop(data->mlx);
	}
	ft_putendl_fd("Usage : ./fdf <filename>", 2);
}

/*
**	https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
**
**	https://qst0.github.io/ft_libgfx/man_data.html
**
**	LAST COPY FT_ERROR TO OWN LIBFT !!
*/
