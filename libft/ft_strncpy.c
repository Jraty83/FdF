/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:44:49 by jraty             #+#    #+#             */
/*   Updated: 2020/07/03 15:48:58 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) + 1 >= len)
	{
		while (src[i] && len--)
		{
			dst[i] = src[i];
			++i;
		}
		if (src[i] == '\0')
			dst[i] = '\0';
		return (dst);
	}
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	while (len - i)
	{
		dst[i] = '\0';
		++i;
	}
	return (dst);
}
