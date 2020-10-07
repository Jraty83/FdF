/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:46:51 by jraty             #+#    #+#             */
/*   Updated: 2020/07/14 13:14:58 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayst, const char *ndl, size_t len)
{
	size_t	n;

	n = ft_strlen(ndl);
	if (!(*ndl))
		return ((char*)hayst);
	while (*hayst && (n <= len--))
	{
		if (ft_strncmp(hayst, ndl, n) == 0)
			return ((char*)hayst);
		hayst++;
	}
	return (NULL);
}
