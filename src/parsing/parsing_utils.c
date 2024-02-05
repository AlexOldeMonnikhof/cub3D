/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:24:50 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/05 16:18:42 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	*str_n_copy(const char *src, int start)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) - start + 1));
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

int	check_ends_line(char *line, int start)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1')
		return (-1);
	while (line[i] == '1' || line[i] == '0'
		|| line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
		i++;
	if (line[i - 1] != '1')
		return (-1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int	check_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '1')
		return (-1);
	while (line[i] == '1' || line[i] == ' ')
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int	find_map_start(char **cub)
{
	int	i;

	i = 0;
	while (cub[i] != NULL && ft_strncmp(cub[i], "111", 3) != 0)
		i++;
	return (i);
}
