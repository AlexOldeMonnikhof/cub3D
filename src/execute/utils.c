/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:57:28 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/13 14:24:09 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	find_dir(t_data *data)
{
	t_ray	*ray;

	ray = data->ray;
	if (ray->vertical_wall_hit == true && ray->y_ray_dir < 0)
		return (NORTH);
	else if (ray->vertical_wall_hit == true)
		return (SOUTH);
	if (ray->x_ray_dir < 0)
		return (WEST);
	return (EAST);
}

void	calculate_draw_vars(t_data *data)
{
	data->line_height = HEIGHT / data->ray->perp_wall_dist;
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0 || data->draw_start > data->draw_end
		|| data->draw_start > HEIGHT)
	{
		data->draw_start = 0;
		data->draw_end = HEIGHT;
	}
}

void	free_textures(t_data *data, int texture)
{
	int	i;

	i = 0;
	mlx_delete_texture(data->text_arr[texture]);
}

static uint32_t	rgba_to_uint(uint8_t *pixels, int i)
{
	uint32_t	ret;

	pixels += i * 4;
	ret = 0;
	ret += *pixels++ << 24;
	ret += *pixels++ << 16;
	ret += *pixels++ << 8;
	ret += 255;
	return (ret);
}

// **pixels = north, east, south, west
// *pixels = uint32_t color code for every pixel.
void	texture_to_doubleptr(t_data *data)
{
	int	pixel_count;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		pixel_count = data->text_arr[i]->width * data->text_arr[i]->height;
		data->pixels[i] = ft_malloc(sizeof(uint32_t) * pixel_count);
		j = 0;
		while (j < pixel_count)
		{
			data->pixels[i][j] = rgba_to_uint(data->text_arr[i]->pixels, j);
			j++;
		}
		i++;
	}
}
