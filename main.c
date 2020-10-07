/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:10:20 by jraty             #+#    #+#             */
/*   Updated: 2020/10/07 13:03:14 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		pxl_ptr;	
	void	*img_ptr;
	char	*img_data;
	int     bpp;
	int     size_line;
	int     endian;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	pxl_ptr = mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 212);
	img_ptr = mlx_new_image(mlx_ptr, 250, 250);
	img_data = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);
	mlx_loop(mlx_ptr);
}
