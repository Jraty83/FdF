/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 09:46:51 by jraty             #+#    #+#             */
/*   Updated: 2020/07/13 18:24:02 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;

	i = 0;
	if (*needle == '\0')
		return ((char*)haystack);
	while (haystack[i])
	{
		while (haystack[i] != needle[i] && haystack[i])
			haystack++;
		i = 0;
		while (haystack[i] && haystack[i] == needle[i])
			i++;
		if (needle[i] == '\0')
			return ((char*)haystack);
	}
	return (NULL);
}
