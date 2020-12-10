/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:52:04 by jraty             #+#    #+#             */
/*   Updated: 2020/12/10 10:53:32 by jraty            ###   ########.fr       */
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
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 155, YELLOW, "BACKGROUND RED: Press key 'r'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 175, YELLOW, "BACKGROUND GREEN: Press key 'g'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 195, YELLOW, "BACKGROUND BLUE: Press key 'b'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 215, YELLOW, "BACKGROUND PURPLE: Press key 'p'");
	mlx_string_put(data->mlx, data->win, data->TEXT_MARGIN, 235, YELLOW, "BACKGROUND BLACK: Press key 'q'");
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
	
	len = 0;
	data->coords = (data->nr_lines * data->line_length);
	printf("\033[01;32mfirst pixel [%d,%d]\033[0m\n", data->x1, data->y1);
//	mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, RED); // DON'T NEED WHEN DRAWING LINES
	data->x2 = data->x1;
	data->y2 = data->y1;
	// printf("x2 %d\ty2 %d\n", data->x2, data->y2);
	while (--data->coords)
//	while (--data->coords >= -1)
	{
		data->x2 += data->zoom;
//		printf("x_offset %d\tx1 %d\tx2 %d\ny_offset %d\ty1 %d\ty2 %d\n", data->x_offset, data->x1, data->x2, data->y_offset, data->y1, data->y2);
		printf("draw line from x1,y1[%d,%d] to x2,y2[%d,%d]\tlen %d\n", data->x1, data->y1, data->x2, data->y2, len);
		draw_line(data, data->x1, data->y1, data->x2, data->y2, data->line_color);
//		data->x1 = data->x2;
//		data->y1 = data->y2;
		if (++len == data->line_length)
		{
			len = 0;
			data->x2 = data->x1;
			data->y2 += data->zoom;
		}
//		printf("x2 %d\ty2 %d\tlen %d\tremaining %d\n", data->x2, data->y2, len, data->coords);
		mlx_pixel_put(data->mlx, data->win, data->x2, data->y2, data->line_color);
	}
	printf("\033[01;31mx1,y1 after pixel draw [%d,%d]\033[0m\n", data->x1, data->y1);
}

void	draw(t_data *data)
{
	draw_background(data);
	instructions(data);
	draw_pixels(data);
//	draw_line(data, data->x1, data->y1, data->x2, data->y2, data->line_color);
}
