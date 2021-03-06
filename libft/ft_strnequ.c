/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:29:01 by jraty             #+#    #+#             */
/*   Updated: 2020/07/16 13:36:23 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (*s1 == *s2 && *s1 && *s2 && i < n)
	{
		++s1;
		++s2;
		++i;
	}
	return ((*s1 == '\0' && *s2 == '\0') || (i == n));
}
