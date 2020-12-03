/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:50:00 by jraty             #+#    #+#             */
/*   Updated: 2020/12/03 12:32:14 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_validator(int fd)
{
	char	*line;
	int		end;
	int		length[1024];

	end = 0;
	while (get_next_line(fd, &line) == 1)
		length[end++] = ft_strlenws(line, ' ');
	if (--end < 0)
	{
		ft_putstr("No data found.\n");
		return (0);
	}
	while (end)
	{
		if (length[end] != length[end - 1])
		{
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		else
			end--;
	}
	free(line);
	return (1);
}
