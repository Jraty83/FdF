/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:05:55 by jraty             #+#    #+#             */
/*   Updated: 2020/12/02 14:32:30 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include "libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>																			// FOR PERROR AND STRERROR

typedef struct		s_window
{
	void			*mlx;
	void			*win;
}					t_window;

typedef struct		s_coord
{
	int				x[1024];
	int				y[1024];
	int				z[1024];
	struct s_coord	*next;
}					t_coord;

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

typedef struct	s_keys
{
	int				esc:1;
}					t_keys;

int					map_validator(int fd);
int					ft_strlenws(const char *s, char c);
int					draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);
void				background(void *mlx_ptr, void *win_ptr, int color);

#endif
