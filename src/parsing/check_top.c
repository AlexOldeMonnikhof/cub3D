/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:21:59 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/05 16:19:34 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_top_map(char **cub, int f_l)
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

int	check_position(char *line, char *dir)
{
	int		i;
	int		j;
	char	*str;
	int		fd;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (dir[j] != '\0')
	{
		if (line[i++] != dir[j++])
			exit(EXIT_FAILURE);
	}
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	fd = 0;
	str = NULL;
	str = str_n_copy(line, i);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	free(str);
	return (1);
}

int	check_colors(char *line, char *dir)
{
	int	error;

	error = check_position_c(line, dir);
	if (error != 0)
		return (0);
	error = check_three_variables(line);
	if (error != 0)
		return (0);
	error = is_valid_format(line);
	if (error != 0)
		return (0);
	error = validate_numbers_in_range(line);
	if (error != 0)
		return (0);
	return (1);
}

int	check_position_c(char *line, char *dir)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (dir[j] != '\0')
	{
		if (line[i] != dir[j])
			return (1);
		i++;
		j++;
	}
	if (line[i] < '0' || line[i] > '9')
		return (1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (0);
}

int	check_three_variables(char *line)
{
	int	i;
	int	count;
	int	count_lenght;

	i = 0;
	count = 0;
	count_lenght = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			count++;
			while (line[i] >= '0' && line[i++] <= '9')
				count_lenght++;
			if (count_lenght > 3)
				return (2);
			count_lenght = 0;
		}
		else
			i++;
	}
	if (count != 3)
		return (2);
	return (0);
}