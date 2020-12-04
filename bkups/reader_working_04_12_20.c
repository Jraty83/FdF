/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:50:00 by jraty             #+#    #+#             */
/*   Updated: 2020/12/04 15:29:35 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_strlenmap(const char *s, t_data *data)
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
	data->line_length = k;
	return (k);
}

void		map_validator(int *llen, t_data *data)
{
	int		i;

	if (data->nr_lines == 0)
		ft_error(1);
	i = 0;
	while (llen[i])
	{
		if (llen[i] != llen[i + 1] && ((i + 1) != data->nr_lines))
		{
			ft_putendl("Found wrong line length. Exiting.");
			exit(0);
		}
		else
			i++;
	}
}

int			ft_reader(int fd, t_data *data)
{
	char	*line;
	int		length[50000];
	int		i;
	int		ret;

	i = 0;
	if (!(data->file = (char**)malloc(sizeof(char*) * 50000)))
		ft_error(2);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		length[i] = ft_strlenmap(line, data);
		data->file[i++] = ft_strdup(line);
		free(line); // NOT REALLY FREEING ANYTHING ?!?
	}
	if (ret < 0)
		ft_error(3);
	data->file[i] = NULL;
//	printf("number of lines: [%d]\n", i);
	data->nr_lines = i;
	map_validator(length, data);
	return (1);
}
