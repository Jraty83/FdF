/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 15:05:55 by jraty             #+#    #+#             */
/*   Updated: 2020/10/09 13:23:59 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H__
# define __FDF_H__

#include "libft/libft.h"
#include <fcntl.h>
#include <math.h>
#include <mlx.h>
#include <stdio.h>																			// FOR PERROR AND STRERROR

typedef struct	s_window
{
	void		*mlx;
	void		*win;
}				t_window;

# define KEY_ESC 0
//# define ESC 27			// esc has an ascii value of 27

typedef struct	s_keys
{
	int			esc:1;
}				t_keys;

#endif
