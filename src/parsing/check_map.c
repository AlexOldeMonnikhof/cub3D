/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:27:53 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/09 17:18:17 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_map(char **cub, int f_l, t_data *data)
{
	int	error;

	error = 0;
	error = check_first_line_map(cub[f_l]);
	if (error == -1)
		return (-1);
	error = check_map_loop(cub, f_l);
	if (error == -1)
		return (-1);
	error = check_endings_map(cub, f_l);
	if (error == -1)
		return (-1);
	error = check_player(cub, f_l, data);
	if (error == -1)
		return (-1);
	return (error);
}

int	check_first_line_map(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i] == '1')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int	check_map_loop(char **cub, int f_l)
{
	int	i;
	int	error;

	i = f_l;
	error = 0;
	i++;
	while (cub[i] != NULL)
	{
		error = check_up_and_main(cub[i], cub[i - 1]);
		if (error == -1)
		{
			printf("error in maploop: %d\n", error);
			return (-1);
		}
		i++;
	}
	return (1);
}

int	check_up_and_main(char *main, char *up)
{
	int	len_up;
	int	len_main;
	int	i;

	len_up = ft_strlen(up);
	len_main = ft_strlen(main);
	i = 0;
	while (i < len_main)
	{
		if (main[i] == '0' || main[i] == 'N' || main[i] == 'S'
			|| main[i] == 'E' || main[i] == 'W')
		{
			if (i >= len_up || up[i] == ' ' || main[i + 1] == ' '
				|| main[i - 1] == ' ')
				return (-1);
		}
		if (main[i] == ' ')
		{
			if (up[i] == '0' || up[i] == 'N'
				|| up[i] == 'S' || up[i] == 'E' || up[i] == 'W')
				return (-1);
		}
		i++;
	}
	return (1);
}

int	check_endings_map(char **cub, int start)
{
	int	error;

	error = 0;
	start++;
	while (cub[start] != NULL)
	{
		error = check_ends_line(cub[start], start);
		if (error == -1)
			return (-1);
		start++;
	}
	error = check_last_line(cub[start - 1]);
	if (error == -1)
		return (-1);
	return (1);
}
