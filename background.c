/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:09:06 by jraty             #+#    #+#             */
/*   Updated: 2020/12/09 13:35:38 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_background(t_data *data)
{
		char	*buffer;
		int		pixel_bits;
		int		line_bytes;
		int		endian;
		int		pixel;
		int		x;
		int		y;

		data->image = mlx_new_image(data->mlx, data->MAP_WIDTH, data->MAP_HEIGHT);
		buffer = mlx_get_data_addr(data->image, &pixel_bits, &line_bytes, &endian);
		if (pixel_bits != 32)
			data->bg_color = mlx_get_color_value(data->mlx, data->bg_color);
		x = 0;
		y = 0;
		while (x < data->MAP_WIDTH && y < data->MAP_HEIGHT)
		{
			pixel = (y * line_bytes) + (x * 4);
			if (endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (data->bg_color >> 24);
				buffer[pixel + 1] = (data->bg_color >> 16) & 0xFF;
				buffer[pixel + 2] = (data->bg_color >> 8) & 0xFF;
				buffer[pixel + 3] = (data->bg_color) & 0xFF;
			}
			else if (endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (data->bg_color) & 0xFF;
				buffer[pixel + 1] = (data->bg_color >> 8) & 0xFF;
				buffer[pixel + 2] = (data->bg_color >> 16) & 0xFF;
				buffer[pixel + 3] = (data->bg_color >> 24);
			}
			++x;
			if (x == data->MAP_WIDTH)
			{
				x = 0;
				++y;
			}
		}
		mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
