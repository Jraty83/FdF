/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/11/30 15:01:41 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* For your mandatory part, you are allowed to use the following functions:
	◦ open, read, write, close
	◦ malloc, free
	◦ perror, strerror
	◦ exit*/

#include "libft/libft.h"
//#include "keys.h"
#include <math.h>
#include "mlx.h"

// #include <mlx.h>

// int		deal_mouse(int mouse, void *param)		// PALAUTA, POISTA ALEMPI
int		deal_mouse(void)
{
	ft_putnbr(3);
//	mlx_pixel_put(mlx_ptr, win_ptr, 50, 50, 212);
	return (0);
}

// int		deal_key(int key, void *param)			// PALAUTA, POISTA ALEMPI
int		deal_key(void)
{
	ft_putchar('X');
//	mlx_pixel_put(mlx_ptr, win_ptr, 50, 50, 212);
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	int		color;

	color = 0xABCDEF;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 360, "mlx 42");
	image = mlx_new_image(mlx_ptr, 640, 360);
	buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);
	mlx_key_hook(win_ptr, deal_key, (void*)0);
	mlx_mouse_hook(win_ptr, deal_mouse, (void*)0);
	if (pixel_bits != 32)
		color = mlx_get_color_value(mlx_ptr, color);

	for(int y = 0; y < 360; ++y)
	for(int x = 0; x < 640; ++x)
	{
		int pixel = (y * line_bytes) + (x * 4);

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
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, image, 0, 0);
	mlx_loop(mlx_ptr);
}

// how to pass parameters to mlx_pixel_put using mlx_key_hook's (void*)0 ?

// use GNL to parse file 42.fdf

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm

// https://qst0.github.io/ft_libgfx/man_mlx.html
