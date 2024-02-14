/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:17 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 17:11:45 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <fcntl.h>

#define INITIAL_CAPACITY 10

static char	**process_line(char **array, char *line, int *num_rows)
{
	size_t	read;

	read = ft_strlen(line);
	if (line[read - 1] == '\n')
		line[read - 1] = '\0';
	array[*num_rows] = malloc((read + 1) * sizeof(char));
	if (!array[*num_rows])
		return (NULL);
	ft_strcpy(array[*num_rows], line);
	(*num_rows)++;
	return (array);
}

char	**resize_array(char **array, int *capacity, int num_rows)
{
	int		i;
	int		old_capacity;
	int		new_capacity;
	char	**temp;

	old_capacity = *capacity;
	new_capacity = 2 * *capacity + 1;
	temp = ft_realloc(array, old_capacity, new_capacity);
	if (temp == NULL)
	{
		i = 0;
		while (i < num_rows)
			free(array[i++]);
		free(array);
		return (NULL);
	}
	*capacity = new_capacity;
	return (temp);
}

char	**initialize_array(int *capacity)
{
	char	**array;

	array = malloc((*capacity + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	return (array);
}

char	**read_and_store_lines(int fd, char **array, int *n_r, int *cap)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (*n_r == *cap)
		{
			array = resize_array(array, cap, *n_r);
			if (!array)
			{
				free(line);
				return (NULL);
			}
		}
		array = process_line(array, line, n_r);
		free(line);
		if (!array)
			break ;
		line = get_next_line(fd);
	}
	return (array);
}

char	**read_cub_file_to_2d_array(const char *filename, int *num_rows)
{
	int		fd;
	int		capacity;
	char	**array;

	capacity = INITIAL_CAPACITY;
	*num_rows = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	array = initialize_array(&capacity);
	if (!array)
	{
		close(fd);
		return (NULL);
	}
	array = read_and_store_lines(fd, array, num_rows, &capacity);
	if (array)
		array[*num_rows] = NULL;
	close(fd);
	return (array);
}
