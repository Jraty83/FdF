/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator_shortened.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:50:00 by jraty             #+#    #+#             */
/*   Updated: 2020/12/03 12:32:46 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		map_validator(int fd)
{
	char	*line;
	int		i;
	int		end;
	int		length[1024];

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		length[i] = ft_strlenws(line, ' ');
//		printf("validator line[%d] length is: %d\n", i, length[i]);
		i++;
	}
	i--;
//	printf("i is: %d\n", i);
	if (i < 0)
	{
		ft_putstr("No data found.\n");
		return (0);
	}
	end = i;
	i = 0;
	while (i < end)
	{
		if (length[i] != length[i + 1])
		{
//			printf("line[%d] WRONG!!!, length %d\n", i, length[i]);
//			printf("line[%d] length %d\n", i+1, length[i+1]);
			ft_putstr("Found wrong line length. Exiting.\n");
			return (0);
		}
		else
		{
//			printf("line[%d] OK, length %d\n", i, length[i]);
			i++;
		}
	}
	return (1);
}
