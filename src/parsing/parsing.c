/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:58:49 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/13 13:31:40 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_texture(char **cub, int i, char *texture)
{
	int	error;

	error = check_position(cub[i], texture);
	if (error == 1)
		return (-1);
	return (0);
}

int	find_first_line_mapp(char **original_a)
{
	int	index;
	int	i;

	i = 0;
	index = 0;
	while (original_a[index] != NULL)
	{
		while (original_a[index][i] == ' ' || original_a[index][i] == '\t')
			i++;
		if (original_a[index][i] == '1' || original_a[index][i] == '0')
			return (index);
		else
			index++;
	}
	return (-1);
}

int	check_amount(char **cub, int f_l)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < f_l)
	{
		if (ft_strnstr(cub[i], "NO ", ft_strlen(cub[i])))
			count += check_position(cub[i], "NO ");
		if (ft_strnstr(cub[i], "SO ", ft_strlen(cub[i])))
			count += check_position(cub[i], "SO ");
		if (ft_strnstr(cub[i], "WE ", ft_strlen(cub[i])))
			count += check_position(cub[i], "WE ");
		if (ft_strnstr(cub[i], "EA ", ft_strlen(cub[i])))
			count += check_position(cub[i], "EA ");
		if (ft_strnstr(cub[i], "C ", ft_strlen(cub[i])))
			count += check_colors(cub[i], "C ");
		if (ft_strnstr(cub[i], "F ", ft_strlen(cub[i])))
			count += check_colors(cub[i], "F ");
		i++;
	}
	if (count != 6)
		return (-1);
	return (1);
}

int	parsing(char **twod, t_data *data)
{
	int	error;
	int	f_l;
	int	error_dos;

	f_l = 0;
	error = 0;
	f_l = find_first_line_map(twod);
	error = check_top_map(twod, f_l);
	error_dos = check_amount(twod, f_l);
	if (error == -1 || error_dos == -1 || f_l == -1)
		return (-1);
	error = check_map(twod, f_l, data);
	if (error == -1)
		return (-1);
	return (1);
}
