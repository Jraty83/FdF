/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:00:52 by jraty             #+#    #+#             */
/*   Updated: 2020/07/16 13:42:04 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*ret;

	if (!s)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*str) * ft_strlen(s) + 1)))
		return (NULL);
	ret = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (ret);
}
