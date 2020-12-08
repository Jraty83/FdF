/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 10:51:22 by jraty             #+#    #+#             */
/*   Updated: 2020/12/08 15:56:25 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_mouse(int button, int x, int y, t_data *data)
{
	ft_putnbr(button);
	if (button == MOUSE_SCROLL_UP)
		data->zoom -= 5;
	if (button == MOUSE_SCROLL_DOWN)
		data->zoom += 5;
	if (button == MOUSE_CENTER)
		data->zoom = 20;
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
	if (key == LEFT)
		data->x_orig -= data->move;
	if (key == RIGHT)
		data->x_orig += data->move;
	if (key == UP)
		data->y_orig -= data->move;
	if (key == DOWN)
		data->y_orig += data->move;
	draw(data);
	return (1);
}
