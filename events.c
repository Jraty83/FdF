/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:51:22 by jraty             #+#    #+#             */
/*   Updated: 2020/12/11 00:39:55 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_colors(int key, t_data *data)
{
	ft_putnbr(key);
	if (key == C)
	{
		if (data->bg_color == BLACK)
		{
			data->bg_color = ORANGE;
			data->line_color = BLUE;
		}
		else if (data->bg_color == ORANGE)
		{
			data->bg_color = GREEN;
			data->line_color = PURPLE;
		}
		else if (data->bg_color == GREEN)
		{
			data->bg_color = BLUE;
			data->line_color = ORANGE;
		}
		else if (data->bg_color == BLUE)
		{
			data->bg_color = PURPLE;
			data->line_color = WHITE;
		}
		else if (data->bg_color == PURPLE)
		{
			data->bg_color = BLACK;
			data->line_color = GREEN;
		}
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
		data->x_start -= data->move;
	if (key == RIGHT)
		data->x_start += data->move;
	if (key == UP)
		data->y_start -= data->move;
	if (key == DOWN)
		data->y_start += data->move;
	if (key == Z)
		if (data->move <= (data->move_offset * 10))
			data->move *= 2;
	if (key == X)
		if (data->move > data->move_offset)
			data->move /= 2;
	return (key_colors(key, data));
}

int		deal_mouse(int button, int x, int y, t_data *data)
{
	ft_putnbr(button);
	if (button == MOUSE_SCROLL_UP)
//		data->zoom -= 5;
		if (data->zoom > data->zoom_offset)
			data->zoom /= 2;
	if (button == MOUSE_SCROLL_DOWN)
//		data->zoom += 5;
		if (data->zoom <= (data->zoom_offset * 20))
			data->zoom *= 2;
	if (button == MOUSE_CENTER)
	{
		data->zoom = data->zoom_offset;
		data->move = data->move_offset;
		data->x_start = data->x_offset;
		data->y_start = data->y_offset;
	}
	draw(data);
	return (1);
}
