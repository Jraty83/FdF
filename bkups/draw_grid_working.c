/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_working.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:52:04 by jraty             #+#    #+#             */
/*   Updated: 2020/12/10 23:29:04 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 15, YELLOW, "ZOOM IN: mouse scroll down");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 35, YELLOW, "ZOOM OUT: mouse scroll up");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 55, YELLOW, "RESET SIZE: mouse center button");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 75, YELLOW, "MOVE MAP LEFT: Press key 'left'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 95, YELLOW, "MOVE MAP UP: Press key 'up'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 115, YELLOW, "MOVE MAP RIGHT: Press key 'right'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 135, YELLOW, "MOVE MAP DOWN: Press key 'down'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 155, YELLOW, "BACKGROUND RED: Press key 'r'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 175, YELLOW, "BACKGROUND GREEN: Press key 'g'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 195, YELLOW, "BACKGROUND BLUE: Press key 'b'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 215, YELLOW, "BACKGROUND PURPLE: Press key 'p'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 235, YELLOW, "BACKGROUND BLACK: Press key 'q'");
}

int 	draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color)
{
	printf("draw line from x1,y1[%d,%d] to x2,y2[%d,%d]\n", data->x1, data->y1, data->x2, data->y2);
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
//		printf("pixelX [%f]\t", pixelX);	// TEST - REMOVE
		pixelY += deltaY;
//		printf("pixelY [%f]\n", pixelY);	// TEST - REMOVE
		--pixels;
	}
	return (0);
}

void	draw_pixels(t_data *data)
{
	int		len;
	int		rows;
	
	len = 1;
	rows = data->nr_lines;
	printf("\033[01;32mfirst pixel x1,y1[%d,%d]  x2,y2[%d,%d]\033[0m\n", data->x1, data->y1, data->x2, data->y2);
	data->x2 = (data->x1 + data->zoom);
	while (rows--)
	{
		while (len != data->line_length)
		{
			data->y2 = data->y1;
			draw_line(data, data->x1, data->y1, data->x2, data->y2, data->line_color);
			if (rows)
			{
				data->x2 = data->x1;
				data->y2 += data->zoom;
				draw_line(data, data->x1, data->y1, data->x2, data->y2, data->line_color);
				data->y2 = data->y1;
				data->x2 = (data->x1 + data->zoom);
			}
			data->x1 = data->x2; // MOVE THE LINE
			data->y1 = data->y2;
			data->x2 += data->zoom;
			++len;
		}
		if (len == data->line_length)
		{
			if (rows)
			{
				data->x2 = data->x1;
				data->y2 += data->zoom;
				draw_line(data, data->x1, data->y1, data->x2, data->y2, data->line_color);
				data->y2 = data->y1;
				data->x2 = (data->x1 + data->zoom);
			}
			len = 1;
			data->x1 = data->x_offset;
			data->x2 = (data->x1 + data->zoom);
			data->y1 += data->zoom;
		}
	}
	printf("\033[01;31mafter pixel draw x1,y1[%d,%d]  x2,y2[%d,%d]\033[0m\n", data->x1, data->y1, data->x2, data->y2);
}

void	draw(t_data *data)
{
	data->x1 = data->x_offset;
	data->y1 = data->y_offset;
	draw_background(data);
	instructions(data);
	draw_pixels(data);
}
