/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_start_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:19:14 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/12 14:56:09 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	get_start_point(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	return (i);
}

int	ft_strncmp_c(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s1[j] == ' ')
		j++;
	while ((s1[j + i] || s2[i]) && i < n)
	{
		if ((s1[j + i] != s2[i]))
			return ((unsigned char)(s1[i]) - (unsigned char)(s2[i]));
		i++;
	}
	return (0);
}

int	check_commas(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (3);
	return (0);
}

int	check_valid_chars(char *line)
{
	int	i;

	i = 0;
	while ((line[i] >= '0' && line[i] <= '9')
		|| line[i] == ' ' || line[i] == 'C'
		|| line[i] == ',' || line[i] == 'F')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (0);
}
