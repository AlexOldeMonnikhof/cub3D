/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:58:49 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/05 16:04:12 by dtunderm         ###   ########.fr       */
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

int	parsing(char **twod, t_data *data)
{
	int	error;
	int	f_l;

	f_l = 0;
	error = 0;
	f_l = find_first_line_map(twod);
	error = check_top_map(twod, f_l);
	if (error == -1)
		return (-1);
	error = check_map(twod, f_l, data);
	if (error == -1)
		return (-1);
	return (1);
}
