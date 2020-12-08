/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:52:04 by jraty             #+#    #+#             */
/*   Updated: 2020/12/08 16:05:58 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 15, YELLOW, "ZOOM IN: mouse scroll down");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 35, YELLOW, "ZOOM OUT: mouse scroll up");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 55, YELLOW, "RESET: mouse center button");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 75, YELLOW, "MOVE MAP LEFT: Press key 'left'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 95, YELLOW, "MOVE MAP UP: Press key 'up'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 115, YELLOW, "MOVE MAP RIGHT: Press key 'right'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 135, YELLOW, "MOVE MAP DOWN: Press key 'down'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 155, YELLOW, "BACKGROUND GREEN: Press key 'g'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 175, YELLOW, "BACKGROUND RED: Press key 'r'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 195, YELLOW, "BACKGROUND BLUE: Press key 'b'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 215, YELLOW, "BACKGROUND BLACK: Press key 'q'");
}

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
//	int		gap;
	
	len = 0;
//	gap = 20;
	data->coords = (data->nr_lines * data->line_length);
	mlx_pixel_put(data->mlx, data->win, data->x_orig, data->y_orig, data->line_color);
	data->x_next = data->x_orig;
	data->y_next = data->y_orig;
//	printf("x_orig %d\ty_orig %d\tlen %d\tEI PRINTATA\n", data->x, data->y, len);
	// printf("x_next %d\ty_next %d\n", data->x_next, data->y_next);
	while (--data->coords)
	{
		data->x_next += data->zoom;
		if (++len == data->line_length)
		{
			len = 0;
			data->x_next = data->x_orig;
			data->y_next += data->zoom;
		}
//		printf("x_next %d\ty_next %d\tlen %d\tremaining %d\n", data->x_next, data->y_next, len, data->coords);
		mlx_pixel_put(data->mlx, data->win, data->x_next, data->y_next, data->line_color);
	}
}

void	draw(t_data *data)
{
	draw_background(data);
	instructions(data);
	draw_pixels(data);
//	draw_line(data, data->x, data->y, data->x_next, data->y_next, pix_color);
}
