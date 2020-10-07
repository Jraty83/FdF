/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:08:59 by jraty             #+#    #+#             */
/*   Updated: 2020/07/01 09:47:33 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int		i;

	i = 0;
	while (*s1 == *s2 && *s1 && *s2 && i < n)
	{
		++s1;
		++s2;
		++i;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
