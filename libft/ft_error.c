/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:42:46 by jraty             #+#    #+#             */
/*   Updated: 2020/12/03 15:03:27 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 0 = Invalid file
// 1 = No data found.

void	ft_error(int err)
{
	if (err == 0)
		ft_putendl_fd("Invalid file", 2);
	if (err == 1)
		ft_putendl_fd("No data found.", 2);
	exit(0);
}
