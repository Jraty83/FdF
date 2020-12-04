/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:50:00 by jraty             #+#    #+#             */
/*   Updated: 2020/12/04 11:58:38 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_strlenmap(const char *s)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while ((s[i] && s[i] == ' ' || s[i] == '-'))
			i++;
		if (s[i] >= '0' && s[i] <= '9')
			k++;
		while (s[i] && s[i] != ' ' && s[i] != '-')
			i++;
	}
//	printf("strlen: %d\ti is: %d\t", k, i);
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
		length[end++] = ft_strlenmap(line);
		printf("\033[32m%s\033[0m\n", line);
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
