/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 12:29:06 by jraty             #+#    #+#             */
/*   Updated: 2020/12/10 22:41:19 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parse_int(t_data *data)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
//	printf("PARSERRRRRR\n");
	if (!(data->height = (int*)malloc(sizeof(int*) * 50000)))
		ft_error(3);
	while (data->file[i])
	{
		line = data->file[i];
		while (*line)
		{
			while (*line && *line == ' ')
				line++;
			data->height[j++] = ft_atoi(line);
//			printf("%d", data->height[j++]);
//			j++;
//			printf("%d", data->height[j]);
			while (*line && *line != ' ')
				line++;
		}
//		free(line);
		i++;
	}
//	data->height[j] = NULL;
	int		ints;
	
	ints = (data->nr_lines * data->line_length);
	j = 0;
//	while (data->height[j++])
//	while (ints--)	// CHECK INT ARRAY CONTENTS
//		printf("{%d}", data->height[j++]);
}
