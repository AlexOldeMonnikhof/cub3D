/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:43:24 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 15:03:47 by aolde-mo         ###   ########.fr       */
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
