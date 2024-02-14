/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:17 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/14 16:57:08 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <fcntl.h>

static void	process_lines(int fd, char **array)
{
	size_t	read;
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		read = ft_strlen(line);
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		array[i] = malloc((read + 1) * sizeof(char));
		ft_strcpy(array[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	array[i] = NULL;
}

static char	**initialize_array(int num_rows)
{
	char	**array;

	array = ft_malloc((num_rows + 1) * sizeof(char *));
	return (array);
}

static void	count_rows(const char *filename, int *num_rows)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		(*num_rows)++;
		line = get_next_line(fd);
	}
	close(fd);
}

char	**read_cub_file_to_2d_array(const char *filename, int *num_rows)
{
	char	**array;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	*num_rows = 0;
	count_rows(filename, num_rows);
	array = initialize_array(*num_rows);
	process_lines(fd, array);
	return (array);
}
