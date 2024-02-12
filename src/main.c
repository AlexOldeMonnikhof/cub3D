/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:17 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/11 16:13:57 by aolde-mo         ###   ########.fr       */
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
	// raycasting(data);
	// printf("%d\n", data->map[0][20]);
	mlx_loop_hook(data->mlx, &key_hook, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**cub_data;
	int		error;
	int		num_rows;

	error = 0;
	num_rows = count_rows_in_file(argv[1]);
	cub_data = read_cub_file_to_2d_array(argv[1], &num_rows);
	check_input(argc, argv);
	data = ft_malloc(sizeof(t_data));
	error = parsing(cub_data, data);
	final_parse(data, cub_data);
	initialize(data);
	game(data);
	cleanup(data);
	free(cub_data);
	return (0);
}
