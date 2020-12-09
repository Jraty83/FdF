/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:51:22 by jraty             #+#    #+#             */
/*   Updated: 2020/12/09 14:55:10 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_colors(int key, t_data *data)
{
	ft_putnbr(key);
	if (key == BK)
	{
		data->bg_color = BLACK;
		data->line_color = WHITE;
	}
	if (key == P)
	{
		data->bg_color = PURPLE;
		data->line_color = GREEN;
	}
	if (key == R)
	{
		data->bg_color = RED;
		data->line_color = BLUE;
	}
	if (key == G)
	{
		data->bg_color = GREEN;
		data->line_color = PURPLE;
		}
	if (key == BL)
	{
		data->bg_color = BLUE;
		data->line_color = RED;
	}
	draw(data);
	return (1);
}

int		deal_key(int key, t_data *data)
{
	ft_putnbr(key);
	if (key == ESCAPE || key == X_ESCAPE)
	{
		ft_putstr("\n");
		exit(0);
	}
	if (key == LEFT)
		data->x1 -= data->move;
	if (key == RIGHT)
		data->x1 += data->move;
	if (key == UP)
		data->y1 -= data->move;
	if (key == DOWN)
		data->y1 += data->move;
	return (key_colors(key, data));
}

int		deal_mouse(int button, int x, int y, t_data *data)
{
	ft_putnbr(button);
	if (button == MOUSE_SCROLL_UP)
		data->zoom -= 5;
	if (button == MOUSE_SCROLL_DOWN)
		data->zoom += 5;
	if (button == MOUSE_CENTER)
	{
		data->zoom = data->zoom_offset;
		data->x1 = data->x_offset;
		data->y1 = data->y_offset;
	}
	draw(data);
	return (1);
}
