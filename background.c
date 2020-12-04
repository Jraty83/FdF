/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:09:06 by jraty             #+#    #+#             */
/*   Updated: 2020/12/04 15:34:55 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	background(t_data *data)
{
		// void	*image;
		char	*buffer;
		int		pixel_bits;
		int		line_bytes;
		int		endian;
		int		pixel;
		int		x;
		int		y;

//		data->color = YELLOW;
		data->image = mlx_new_image(data->mlx, 640, 360);
		buffer = mlx_get_data_addr(data->image, &pixel_bits, &line_bytes, &endian);
		if (pixel_bits != 32)
			data->color = mlx_get_color_value(data->mlx, data->color);
		x = 0;
		y = 0;
		while (x < 640 && y < 360)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (data->color >> 24);
				buffer[pixel + 1] = (data->color >> 16) & 0xFF;
				buffer[pixel + 2] = (data->color >> 8) & 0xFF;
				buffer[pixel + 3] = (data->color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (data->color) & 0xFF;
				buffer[pixel + 1] = (data->color >> 8) & 0xFF;
				buffer[pixel + 2] = (data->color >> 16) & 0xFF;
				buffer[pixel + 3] = (data->color >> 24);
			}
			++x;
			if (x == 640)
			{
				x = 0;
				++y;
			}
		}
		mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
