/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:39:10 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/18 13:14:53 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <stdio.h>

void	clean_cub_data(char **cub_data, int num_rows, bool valid)
{
	int	i;

	i = 0;
	while (i < num_rows)
		free(cub_data[i++]);
	free(cub_data);
	if (!valid)
		printf("Error\nInvalid .cub file\n");
	exit(EXIT_FAILURE);
}

void	free_mlx_textures(mlx_texture_t **textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (textures[i])
			mlx_delete_texture(textures[i]);
		i++;
	}
	exit(EXIT_FAILURE);
}

void	mlx_error_exit(t_data *data)
{
	if (data->mlx)
		mlx_terminate(data->mlx);
	printf("%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
