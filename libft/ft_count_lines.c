/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:33:31 by jraty             #+#    #+#             */
/*   Updated: 2020/07/29 15:34:33 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_lines(char *s)
{
	size_t	lines;

	if (!s)
		return (0);
	lines = 1;
	while (*s++)
	{
		if (*s == '\n')
			++lines;
	}
	return (lines);
}
