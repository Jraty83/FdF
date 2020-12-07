/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:05:55 by jraty             #+#    #+#             */
/*   Updated: 2020/12/07 13:59:48 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include "libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>	// REMOVE WHEN FINISHED !!

typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*image;
	char	**file;
	int		*height;
	int		color;
	int		nr_lines;
	int		line_length;
	int		coords;
	int		x;
	int		x_next;
	int		y;
	int		y_next;
}					t_data;

# define ESC 27			// esc has an ascii value of 27

// COLORS
# define BLACK	0x000000
# define WHITE	0xFFFFFF
# define RED	0xFF0000
# define GREEN	0x00FF00
# define BLUE	0x0000FF
# define YELLOW	0xFFFF00
# define PURPLE	0x8000FF
# define ORANGE	0xFF8000

int					ft_reader(int fd, t_data *data);
void				parse_int(t_data *data);
void				draw_pixels(t_data *data);
// int					draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void				background(t_data *data);

#endif
