/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:20 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/01/31 14:10:03 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_north_south(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->start_direction == NORTH)
	{
		player->x_dir = 0;
		player->y_dir = -1;
		player->x_plane = 0.66;
		player->y_plane = 0;
	}
	if (data->start_direction == SOUTH)
	{
		player->x_dir = 0;
		player->y_dir = 1;
		player->x_plane = -0.66;
		player->y_plane = 0;
	}
}

static void	init_east_west(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->start_direction == EAST)
	{
		player->x_dir = 1;
		player->y_dir = 0;
		player->x_plane = 0;
		player->y_plane = 0.66;
	}
	if (data->start_direction == WEST)
	{
		player->x_dir = -1;
		player->y_dir = 0;
		player->x_plane = 0;
		player->y_plane = -0.66;
	}
}

void	init_direction(t_data *data)
{
	if (data->start_direction == NORTH || data->start_direction == SOUTH)
		init_north_south(data);
	else
		init_east_west(data);
}
