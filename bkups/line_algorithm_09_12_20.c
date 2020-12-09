/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_algorithm_09_12_20.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 12:52:04 by jraty             #+#    #+#             */
/*   Updated: 2020/12/09 12:07:04 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
