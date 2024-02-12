/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:58:32 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/12 15:07:04 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <stdio.h>
#include <fcntl.h>

int	find_first_line_map(char **orig_ar)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (orig_ar[index] != NULL)
	{
		while (orig_ar[index][i] == ' ')
			i++;
		if (orig_ar[index][i] == '1' || orig_ar[index][i] == '0')
			return (index);
		else
		{
			i = 0;
			index++;
		}
	}
	return (-1);
}

int	count_rows_in_file(const char *filename)
{
	int		fd;
	int		num_rows;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	num_rows = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		num_rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (num_rows);
}
