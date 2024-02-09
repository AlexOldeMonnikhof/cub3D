/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:26:36 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/09 17:19:56 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_valid_format(const char *str)
{
	if (str == NULL)
		return (-1);
	while (*str && !ft_isdigit(*str) && *str != ',')
		str++;
	while (*str)
	{
		if (*str == '0' && ft_isdigit(*(str + 1)))
			return (3);
		while (*str && *str != ',')
			str++;
		if (*str == ',')
		{
			str++;
			while (*str && ft_isspace(*str))
				str++;
			if (*str == '0' && ft_isdigit(*(str + 1)))
				return (3);
		}
	}
	return (0);
}

int	validate_numbers_in_range(const char *str)
{
	char	*next;
	long	num;

	if (str == NULL)
		return (4);
	while (*str)
	{
		while (*str && !ft_isdigit(*str) && *str != '-')
			str++;
		if (!*str)
			break ;
		num = strtol(str, &next, 10);
		if (num < 0 || num > 255)
			return (4);
		str = next;
	}
	return (0);
}

void	process_wall_textures(t_data *data, char **cub)
{
	int	i;
	int	start_point;

	i = 0;
	while (cub[i] != NULL)
	{
		if (ft_strncmp_c(cub[i], "NO ", 3) == 0)
			data->NO = ft_strdup(cub[i] + get_start_point(cub[i]));
		else if (ft_strncmp_c(cub[i], "SO ", 3) == 0)
			data->SO = ft_strdup(cub[i] + get_start_point(cub[i]));
		else if (ft_strncmp_c(cub[i], "WE ", 3) == 0)
			data->WE = ft_strdup(cub[i] + get_start_point(cub[i]));
		else if (ft_strncmp_c(cub[i], "EA ", 3) == 0)
			data->EA = ft_strdup(cub[i] + get_start_point(cub[i]));
		i++;
	}
}

int	char_to_int(char c, t_data *data)
{
	if (c == '1')
		return (1);
	if (c == '0' || c == ' ' || (c >= 0 && c <= 3))
		return (0);
	return (-1);
}

void	process_floor_ceiling_colors(t_data *data, char **cub)
{
	int	i;

	i = 0;
	while (cub[i] != NULL)
	{
		if (ft_strncmp_c(cub[i], "F ", 2) == 0)
		{
			data->F = malloc(3 * sizeof(uint32_t));
			parse_rgb_values(data->F, cub[i] + 2);
		}
		else if (ft_strncmp_c(cub[i], "C ", 2) == 0)
		{
			data->C = malloc(3 * sizeof(uint32_t));
			parse_rgb_values(data->C, cub[i] + 2);
		}
		i++;
	}
}
