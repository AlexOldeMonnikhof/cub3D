/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:24:50 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/14 16:17:31 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*str_n_copy(const char *src, int start)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_malloc(sizeof(char) * (ft_strlen(src) - start + 1));
	if (dest == NULL)
		return (NULL);
	while (src[start] != '\0')
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f'
		|| c == '\n' || c == '\r'
		|| c == '\t' || c == '\v');
}

int	check_ends_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (2);
	if (line[i] != '1')
		return (-1);
	while (line[i] == '1' || line[i] == '0'
		|| line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
		i++;
	i--;
	while (line[i] == ' ')
		i--;
	if (line[i] != '1')
		return (-1);
	i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (2);
	if (line[i] != '1')
		return (-1);
	while (line[i] == '1' || line[i] == ' ')
		i++;
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int	find_map_start(char **cub)
{
	int	i;
	int	j;
	int	one_f;

	j = 0;
	i = 0;
	one_f = 0;
	while (cub[i] != NULL)
	{
		while ((cub[i][j] == '1' || cub[i][j] == ' '))
		{
			if (cub[i][j] == '1')
				one_f = 1;
			j++;
			if (cub[i][j] == '\0' && one_f == 1)
				return (i);
		}
		one_f = 0;
		j = 0;
		i++;
	}
	return (-1);
}
