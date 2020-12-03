/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:50:00 by jraty             #+#    #+#             */
/*   Updated: 2020/12/03 15:56:23 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_strlenmap(const char *s, char c)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] && (s[i] == c || s[i] == '-'))
			i++;
		k++;
		while (s[i] && s[i] != c && s[i] != '-')
			i++;
	}
	return (k);
}

int		map_validator(int fd)
{
	char	*line;
	int		end;
	int		length[50000];

	end = 0;
	while (get_next_line(fd, &line) == 1)
	{
		printf("\033[32m%s\033[0m\n", line);
		length[end++] = ft_strlenmap(line, ' ');
	}
	if (--end < 0)
		ft_error(1);
	while (end)
	{
		if (length[end] != length[end - 1])
		{
			ft_putendl("Found wrong line length. Exiting.");
			return (0);
		}
		else
			end--;
	}
	free(line);
	return (1);
}
