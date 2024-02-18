/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/18 15:38:04 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include "../../libft/libft.h"

#include <unistd.h>

void	print_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}

void	check_input(int argc, char **argv)
{
	if (argc != 2)
		print_error("Wrong amount of arguments. Only *.cub is needed\n");
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		print_error("File must be *.cub\n");
	if (WIDTH < 1 || WIDTH > 2000 || HEIGHT < 1 || HEIGHT > 2000)
		print_error("Inproper width or height\n(0-2000) is allowed\n");
}

void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		printf("Error\nMalloc error\n");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

void	*ft_malloc2(size_t size, char **array, int i)
{
	void	*ret;

	ret = malloc(size);
	if (!ret)
	{
		while (i >= 0)
			free(array[i--]);
		free(array);
		printf("Error\nMalloc error\n");
		exit(EXIT_FAILURE);
	}
	return (ret);
}

bool	is_wall(t_data *data, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = data->player->x_pos;
	old_y = data->player->y_pos;
	if (data->map[new_y][new_x] == WALL)
		return (true);
	if (data->map[new_y][old_x] == WALL)
		return (true);
	if (data->map[old_y][new_x] == WALL)
		return (true);
	return (false);
}
