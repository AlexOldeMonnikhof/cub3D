/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:17 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 15:52:13 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

#include <stdlib.h>
#include <stdio.h>

// void	leakss()
// {
// 	system("leaks cub3d");
// }

static void	game(t_data *data)
{
	raycasting(data);
	mlx_loop_hook(data->mlx, &key_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**cub_data;
	int		num_rows;

	data = NULL;
	check_input(argc, argv);
	num_rows = count_rows_in_file(argv[1]);
	cub_data = read_cub_file_to_2d_array(argv[1], &num_rows);
	data = ft_malloc(sizeof(t_data));
	if (!data)
		clean_cub_data(cub_data, num_rows, false);
	if (parsing(cub_data, data) == -1)
		clean_cub_data(cub_data, num_rows, false);
	final_parse(data, cub_data);
	initialize(data);
	game(data);
	clean_cub_data(cub_data, num_rows, true);
	mlx_terminate(data->mlx);
	return (0);
}
