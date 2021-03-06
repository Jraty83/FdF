/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:52:04 by jraty             #+#    #+#             */
/*   Updated: 2020/12/11 01:02:22 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(t_data *data)
{
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 20, YELLOW, "ZOOM IN/OUT: MOUSE WHEEL");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 40, YELLOW, "RESET STATS: MOUSE MID BUTTON");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 60, YELLOW, "MOVE MAP: USE ARROW KEYS");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 80, YELLOW, "MOVEMENT SPEED +/-: PRESS 'Z/X'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 100, YELLOW, "CHANGE COLORS: PRESS 'C'");
	mlx_string_put(data->mlx, data->win, data->RIGHT_MARGIN, 120, YELLOW, "CLOSE WINDOW: PRESS 'ESC'");
	// STATS
	mlx_string_put(data->mlx, data->win, data->LEFT_MARGIN, 20, YELLOW, "OFFSET X =");
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 65), 20, YELLOW, ft_itoa(data->x_start - data->x_offset));
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 110), 20, YELLOW, "OFFSET Y =");
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 175), 20, YELLOW, ft_itoa(data->y_start - data->y_offset));
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 220), 20, YELLOW, "MOVEMENT SPEED = x");
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 330), 20, YELLOW, ft_itoa(data->move / data->move_offset));
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 360), 20, YELLOW, "ZOOM = x");
	mlx_string_put(data->mlx, data->win, (data->LEFT_MARGIN + 410), 20, YELLOW, ft_itoa(data->zoom / data->zoom_offset));
}

int 	draw_line(t_data *data, int beginX, int beginY, int endX, int endY, int color)
{
//	printf("draw line from x1,y1[%d,%d] to x2,y2[%d,%d]\n", data->x1, data->y1, data->x2, data->y2);
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
//	printf("\033[01;32mfirst pixel x1,y1[%d,%d]  x2,y2[%d,%d]\033[0m\n", data->x1, data->y1, data->x2, data->y2);
	data->x2 = (data->x1 + data->zoom);
	while (rows--)
	{
		while (len != data->line_length)
		{
			data->y2 = data->y1;
/*VAAKA*/	draw_line(data, data->x1, data->y1, data->x2, data->y2, data->line_color);
			if (rows)
/*PYSTYT*/		draw_line(data, data->x1, data->y1, data->x1, (data->y2 + data->zoom), data->line_color);
			data->x1 = data->x2; // MOVE THE LINE
			data->y1 = data->y2;
			data->x2 += data->zoom;
			++len;
		}
		if (len == data->line_length)
		{
			if (rows)
/*VIKA PYSTY*/	draw_line(data, data->x1, data->y1, data->x1, (data->y2 + data->zoom), data->line_color);
			len = 1;
			data->x1 = data->x_start;
			data->x2 = (data->x1 + data->zoom);
			data->y1 += data->zoom;
		}
	}
//	printf("\033[01;31mafter pixel draw x1,y1[%d,%d]  x2,y2[%d,%d]\033[0m\n", data->x1, data->y1, data->x2, data->y2);
}

void	draw(t_data *data)
{
	data->x1 = data->x_start;
	data->y1 = data->y_start;
	draw_background(data);
	instructions(data);
	draw_pixels(data);
}
