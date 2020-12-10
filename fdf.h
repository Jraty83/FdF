/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:05:55 by jraty             #+#    #+#             */
/*   Updated: 2020/12/10 23:30:12 by jraty            ###   ########.fr       */
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
	int		MAP_HEIGHT;
	int		MAP_WIDTH;
	int		LEFT_MARGIN;
	int		RIGHT_MARGIN;
	void	*mlx;
	void	*win;
	void	*image;
	char	**file;
	int		*height;
	int		line_color;
	int		bg_color;
	int		nr_lines;
	int		line_length;
	int		x_offset;
	int		x1;
	int		x2;
	int		y_offset;
	int		y1;
	int		y2;
	int		move_offset;
	int		move;
	int		zoom_offset;
	int		zoom;
}					t_data;

// KEYS
# define ESCAPE 53
# define X_ESCAPE 65307
# define C 99
# define BL 98
# define G 103
# define P 112
# define BK 113
# define R 114
# define X 120
# define Y 121
# define Z 122
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364

// MOUSE
# define MOUSE_LEFT 1
# define MOUSE_CENTER 2
# define MOUSE_RIGHT 3
# define MOUSE_SCROLL_DOWN 4
# define MOUSE_SCROLL_UP 5

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
void				draw(t_data *data);
void				draw_background(t_data *data);
int					deal_key(int key, t_data *data);
int					deal_mouse(int button, int x, int y, t_data *data);

#endif
