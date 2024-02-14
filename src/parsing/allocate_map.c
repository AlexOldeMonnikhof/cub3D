/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:43:16 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/14 17:00:02 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <stdio.h>

char	get_map_char(char **cub, int map_start, int i, int j)
{
	int	len;

	len = ft_strlen(cub[map_start + i]);
	if (j < len)
		return (cub[map_start + i][j]);
	else
		return (' ');
}

static void	populate_map(t_data *data, char **cub, int rows, int cols)
{
	int		i;
	int		j;
	char	c;
	int		map_start;

	i = 0;
	map_start = find_map_start(cub);
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			c = get_map_char(cub, map_start, i, j);
			data->map[i][j] = char_to_int(c);
			j++;
		}
		i++;
	}
}

static void	allocate_map_memory(t_data *data, int rows, int cols)
{
	int	i;

	i = 0;
	data->map = ft_malloc(rows * sizeof(int *));
	while (i < rows)
		data->map[i++] = ft_malloc(cols * sizeof(int));
}

static void	calc_map_dimension(char **cub, int map_s, int *r, int *c)
{
	int	len;
	int	i;

	*r = 0;
	*c = 0;
	i = map_s;
	while (cub[i] != NULL)
	{
		len = ft_strlen(cub[i]);
		if (len > *c)
			*c = len;
		(*r)++;
		i++;
	}
}

void	process_map(t_data *data, char **cub)
{
	int	rows;
	int	cols;
	int	map_start;

	map_start = find_map_start(cub);
	calc_map_dimension(cub, map_start, &rows, &cols);
	allocate_map_memory(data, rows, cols);
	populate_map(data, cub, rows, cols);
}
