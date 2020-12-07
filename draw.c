/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:52:04 by jraty             #+#    #+#             */
/*   Updated: 2020/12/07 15:45:25 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <mlx.h>

int 	draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0

	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(data->mlx, data->win, pixelX, pixelY, color);
		pixelX += deltaX;
//		printf("pixelX [%f]\t", pixelX);										// TEST - REMOVE
		pixelY += deltaY;
//		printf("pixelY [%f]\n", pixelY);										// TEST - REMOVE
		--pixels;
	}
	return (0);
}

void	draw_pixels(t_data *data)
{
	int		len;
	int		gap;
	int		pix_color;
	
	pix_color = RED;
	len = 0;
	gap = 20;
	data->x = 50;
	data->y = 50;
	data->coords = (data->nr_lines * data->line_length);
	mlx_pixel_put(data->mlx, data->win, data->x, data->y, pix_color);
	data->x_next = data->x;
	data->y_next = data->y;
//	printf("x_orig %d\ty_orig %d\tlen %d\tEI PRINTATA\n", data->x, data->y, len);
	// printf("x_next %d\ty_next %d\n", data->x_next, data->y_next);
	while (--data->coords)
	{
		data->x_next += gap;
		if (++len == data->line_length)
		{
			len = 0;
			data->x_next = data->x;
			data->y_next += gap;
		}
//		printf("x_next %d\ty_next %d\tlen %d\tremaining %d\n", data->x_next, data->y_next, len, data->coords);
		mlx_pixel_put(data->mlx, data->win, data->x_next, data->y_next, pix_color);
//		draw_line(data, data->x, data->y, data->x_next, data->y_next, pix_color);
	}
	// Call draw_line
}
/*
int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Draw Line");

    draw_line(mlx, win, 640, 360, 0, 0, 0xFFFFFF);

    mlx_loop(mlx);
}*/
