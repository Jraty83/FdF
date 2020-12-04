/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:42:46 by jraty             #+#    #+#             */
/*   Updated: 2020/12/04 15:46:53 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0 = Open failed
// 1 = Reading failed
// 2 = No data found
// 3 = Malloc failed

void	ft_error(int err)
{
	if (err == 0)
		ft_putendl_fd("Open failed", 2);
	if (err == 1)
		ft_putendl_fd("Reading failed", 2);
	if (err == 2)
		ft_putendl_fd("No data found", 2);
	if (err == 3)
		ft_putendl_fd("Malloc failed", 2);
	exit(0);
}
