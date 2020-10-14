/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:05:55 by jraty             #+#    #+#             */
/*   Updated: 2020/10/14 14:04:34 by jraty            ###   ########.fr       */
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

# define KEY_ESC 0
//# define ESC 27			// esc has an ascii value of 27

typedef struct	s_keys
{
	int				esc:1;
}					t_keys;

int					map_validator(int fd);
int					ft_strlenws(const char *s, char c);
int					draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color);

#endif
