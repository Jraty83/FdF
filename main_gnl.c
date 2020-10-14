/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/10/14 17:44:00 by jraty            ###   ########.fr       */
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
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		color;
	int		fd;
	char	*line;
	int		x;
	int		y;
	char	**split;
	int		elev[1024];
	int		i;
//	int		length;

	i = 0;
//	printf("endian is: [%d]\n", endian);													// TEST - REMOVE
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			printf("No file %s\n", argv[1]);												// REMOVE PRINTF !!
			return (0);
		}
		if (!map_validator(fd))
			return (0);
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &line) == 1)
		{
//			color = 0xC5B358; // Vegas Gold													// TEST - REMOVE
//			color = 0xABCDEF; // Pale Cornflower Blue										// TEST - REMOVE
//			color = 0xEFCDAB; // Desert Sand												// TEST - REMOVE
//			color = 0x00FF00; // Lime														// TEST - REMOVE
			color = 0x000000; // Black														// TEST - REMOVE
//			color = 0xFFFFFF; // White														// TEST - REMOVE
			printf("\033[32m%s\033[0m\n", line);
//			length = ft_strlenws(line, ' ');
//			printf("line length is: %d\n", length);
			split = ft_strsplit(line, ' ');
			while (*split)
			{
//				printf("%s ", split[i++]);
//				printf("%d", ft_getnbr(*split++));
				elev[i++] = ft_getnbr(*split++);
			}
//			i++;
			elev[i] = '\0';
		}
//		printf("elev: %d ", elev[i++]);
		i = 0;
		while (elev[i])
		{
//			coord->z = elev[i];
			printf("elev[%d]: %d\n", i, elev[i]);
//			printf("coord->z[%d]: %d\n", i, coord->z);
			i++;
		}
		free(*split);
//		printf("\033[32m%s\033[0m\n", line);											// TEST - REMOVE
		free (line);																	// TEST - REMOVE
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, 640, 360, "my Fdf");
		mlx_key_hook(win_ptr, deal_key, (void*)0);
		mlx_mouse_hook(win_ptr, deal_mouse, (void*)0);
		image = mlx_new_image(mlx_ptr, 640, 360);
		buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
		if (pixel_bits != 32)
			color = mlx_get_color_value(mlx_ptr, color);
		x = 0;
		y = 0;
		while (x < 640 && y < 360)
		{
			int pixel = (y * line_bytes) + (x * 4);
			mlx_pixel_put(mlx_ptr, win_ptr, ft_getnbr(line), y, 0xEFCDAB);
			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
			++x;
			if (x == 640)
			{
				x = 0;
				++y;
			}
		}
		mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
		mlx_pixel_put(mlx_ptr, win_ptr, elev[4], 120, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, elev[4], 240, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, elev[4], -240, 0xFFFFFF);									// TEST DRAW INSIDE IMAGE - REMOVE
		mlx_pixel_put(mlx_ptr, win_ptr, 120, elev[4], 0xFFFFFF);							// TEST DRAW INSIDE IMAGE - REMOVE
		i = 0;																				// TEST DRAW INSIDE IMAGE - REMOVE
		while (elev[i])																	// TEST DRAW INSIDE IMAGE - REMOVE
		{																					// TEST DRAW INSIDE IMAGE - REMOVE
			mlx_pixel_put(mlx_ptr, win_ptr, elev[i], elev[i], 0xFFFFFF);				// TEST DRAW INSIDE IMAGE - REMOVE
			i++;																			// TEST DRAW INSIDE IMAGE - REMOVE
		}																					// TEST DRAW INSIDE IMAGE - REMOVE
//		draw_line(mlx_ptr, win_ptr, 640, 360, 0, 0, 0xFFFFFF);
		mlx_pixel_put(mlx_ptr, win_ptr, 0, 0, 0x00FF00);;
		draw_line(mlx_ptr, win_ptr, 240, 100, 240, 200, 0xFFFFFF);
		draw_line(mlx_ptr, win_ptr, 400, 100, 400, 200, 0xFFFFFF);
		draw_line(mlx_ptr, win_ptr, 240, 100, 400, 100, 0xFFFFFF);
		draw_line(mlx_ptr, win_ptr, 240, 200, 400, 200, 0xFFFFFF);
		draw_line(mlx_ptr, win_ptr, 240, 100, 400, 200, 0xFFFFFF);
		draw_line(mlx_ptr, win_ptr, 240, 200, 400, 100, 0xFFFFFF);
		mlx_loop(mlx_ptr);
	}
	ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
//	perror("Usage : ./fdf <filename> [ case_size z_size ]\n");								// USE THIS ??
//	printf("%s\n", strerror(0));	// Undefined error: 0									// OR THESE...
//	printf("%s\n", strerror(1));	// Operation not permitted
//	printf("%s\n", strerror(2));	// No such file or directory
//	printf("%s\n", strerror(3));	// No such process
//	printf("%s\n", strerror(4));	// Interrupted system call
//	printf("%s\n", strerror(5));	// Input/output
//	printf("%s\n", strerror(6));	// Device not configured
//	printf("%s\n", strerror(7));	// Argument list too long
//	printf("%s\n", strerror(8));	// Exec format error
//	printf("%s\n", strerror(9));	// Bad file descriptor
}

// how to pass parameters to mlx_pixel_put using mlx_key_hook's (void*)0 ?

// use GNL to parse file 42.fdf

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

// https://qst0.github.io/ft_libgfx/man_mlx.html
