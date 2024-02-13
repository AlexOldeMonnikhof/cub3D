/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:39:10 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/12 19:09:58 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdio.h>

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
		free(data->map[i++]);
	free(data->map);
}

void	free_pixels(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
		free(data->pixels[i++]);
	free(data->pixels);
}

void	cleanup(t_data *data)
{
	free(data->player);
	free(data->ray);
	free(data->no);
	free(data->so);
	free(data->we);
	free(data->ea);
	free(data->f);
	free(data->c);
	free(data->text_arr[0]);
	free(data->text_arr[1]);
	free(data->text_arr[2]);
	free(data->text_arr[3]);
	free(data->text_arr);
	free_pixels(data);
	free_map(data);
}

void	clean_cub_data(char **cub_data, int num_rows)
{
	int	i;

	i = 0;
	while (i < num_rows)
		free(cub_data[i++]);
	free(cub_data);
}