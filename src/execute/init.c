/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:09:47 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 14:29:29 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <stdlib.h>

//adding 0.5 offset to spawn in the middle of block
void	init_player(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->x_pos = data->x_player + 0.5;
	player->y_pos = data->y_player + 0.5;
	if (data->start_direction == NORTH || data->start_direction == SOUTH)
		init_north_south(data);
	else
		init_east_west(data);
}

void	load_textures(t_data *data)
{
	data->text_arr = ft_malloc(sizeof(mlx_texture_t *) * 4);
	data->text_arr[NORTH] = mlx_load_png(data->no);
	data->text_arr[EAST] = mlx_load_png(data->ea);
	data->text_arr[SOUTH] = mlx_load_png(data->so);
	data->text_arr[WEST] = mlx_load_png(data->we);
	if (!data->text_arr[NORTH] || !data->text_arr[EAST]
		|| !data->text_arr[SOUTH] || !data->text_arr[WEST])
		free_mlx_textures(data->text_arr);
	texture_to_doubleptr(data);
}

void	close_mlx(t_data *data)
{
	mlx_close_window(data->mlx);
	mlx_delete_image(data->mlx, data->img);
}

void	initialize(t_data *data)
{
	data->player = ft_malloc(sizeof(t_player));
	init_player(data);
	data->ray = ft_malloc(sizeof(t_ray));
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!data->mlx)
		mlx_error_exit(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img)
	{
		mlx_close_window(data->mlx);
		mlx_error_exit(data);
	}
	data->pixels = ft_malloc(sizeof(uint32_t *) * 4);
	load_textures(data);
	if (mlx_image_to_window(data->mlx, data->img, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		mlx_error_exit(data);
	}
}
