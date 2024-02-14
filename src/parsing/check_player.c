/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:30:22 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/14 17:00:53 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	get_coordinates(t_data *data, char **cub, int start, int i)
{
	data->x_player = i;
	data->y_player = start - data->firstline_map;
	get_start_direction(cub[start][i], data);
	cub[start][i] = '0';
}

int	check_player(char **cub, int start, t_data *data)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	data->firstline_map = start;
	while (cub[start] != NULL)
	{
		while (cub[start][i] != '\0')
		{
			if (cub[start][i] == 'E' || cub[start][i] == 'W'
				|| cub[start][i] == 'N'
				|| cub[start][i] == 'S')
			{
				get_coordinates(data, cub, start, i);
				p++;
			}
			i++;
		}
		i = 0;
		start++;
	}
	if (p != 1)
		return (-1);
	return (1);
}

void	get_start_direction(char c, t_data *data)
{
	if (c == 'N')
		data->start_direction = 0;
	if (c == 'S')
		data->start_direction = SOUTH;
	if (c == 'E')
		data->start_direction = EAST;
	if (c == 'W')
		data->start_direction = WEST;
}
