/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:05:55 by jraty             #+#    #+#             */
/*   Updated: 2020/12/03 14:05:04 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include "libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>																			// FOR PERROR AND STRERROR

typedef struct		s_data
{
	void	*mlx;
	void	*win;
	void	*image;	// only for background.c ?
	char	*buffer;	// only for background.c ?
	char	*line;
	int		fd;
	int		color;
	int		pixel_bits;	// only for background.c ?
	int		line_bytes;	// only for background.c ?
	int		endian;	// only for background.c ?
	int		pixel;	// only for background.c ?
	int		x;	// only for background.c ?
	int		y;	// only for background.c ?
	int		i;
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

int					map_validator(int fd);
int					draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void				background(t_data *data);

#endif
