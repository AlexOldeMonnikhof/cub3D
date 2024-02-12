/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtunderm <dtunderm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:57:30 by dtunderm          #+#    #+#             */
/*   Updated: 2024/02/09 17:10:10 by dtunderm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	calculate_map_dimensions(char **cub, int *rows, int *cols)
{
	int	i;
	int	len;

	*rows = 0;
	*cols = 0;
	i = 0;
	while (cub[i] != NULL && ft_strncmp(cub[i], "111", 3) != 0)
		i++;
	while (cub[i] != NULL)
	{
		(*rows)++;
		len = ft_strlen(cub[i]);
		if (len > *cols)
			*cols = len;
		i++;
	}
}

void	final_parse(t_data *data, char **cub)
{
	int	rows;
	int	cols;

	process_wall_textures(data, cub);
	process_floor_ceiling_colors(data, cub);
	if (data->F)
		printf("F: %u, %u, %u\n", data->F[0], data->F[1], data->F[2]);
	else
		printf("F data not available\n");
	if (data->C)
		printf("C: %u, %u, %u\n", data->C[0], data->C[1], data->C[2]);
	else
		printf("C data not available\n");
	process_map(data, cub);
	calculate_map_dimensions(cub, &rows, &cols);
}

void	parse_rgb_values(uint32_t *color_array, char *rgb_str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		while (*rgb_str && (*rgb_str < '0' || *rgb_str > '9'))
			rgb_str++;
		color_array[i] = parse_int(&rgb_str);
		while (*rgb_str && (*rgb_str >= '0' && *rgb_str <= '9'))
			rgb_str++;
		i++;
	}
}

int	parse_int(char **str)
{
	int	num;

	num = 0;
	while (**str && **str >= '0' && **str <= '9')
	{
		num = num * 10 + (**str - '0');
		(*str)++;
	}
	return (num);
}

uint32_t	rgb_to_uint32(char *rgb_str)
{
	int	r;
	int	g;
	int	b;

	r = parse_int(&rgb_str);
	if (*rgb_str == ',')
		rgb_str++;
	g = parse_int(&rgb_str);
	if (*rgb_str == ',')
		rgb_str++;
	b = parse_int(&rgb_str);
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return ((r << 16) | (g << 8) | b);
	return (0);
}
