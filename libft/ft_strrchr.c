/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:30:06 by jraty             #+#    #+#             */
/*   Updated: 2020/07/07 09:16:55 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		s_len;

	s_len = ft_strlen(s);
	while (*s)
		s++;
	if ((char)c == '\0')
		return ((char*)s);
	s--;
	while (*s != (char)c && s_len--)
		s--;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}
