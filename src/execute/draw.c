/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:48:11 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/12 14:58:22 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <stdio.h>

uint32_t	get_floor_ceiling_rgba(uint32_t *flor_clng)
{
	return (flor_clng[0] << 24 | flor_clng[1] << 16 | flor_clng[2] << 8 | 255);
}

uint32_t	get_pixel_rgba(uint8_t *arr)
{
	return (arr[0] << 24 | arr[1] << 16 | arr[2] << 8 | arr[3]);
}

static void	calculate_x_wall(t_data *data, int direction)
{
	mlx_texture_t	*texture;
	t_player		*player;
	t_ray			*ray;

	texture = data->text_arr[direction];
	player = data->player;
	ray = data->ray;
	ray->x_texture = (int)(ray->x_wall * (double)texture->width);
	if (ray->vertical_wall_hit == true)
		ray->x_wall = player->x_pos + ray->perp_wall_dist * ray->x_ray_dir;
	else
		ray->x_wall = player->y_pos + ray->perp_wall_dist * ray->y_ray_dir;
	ray->x_wall = ray->x_wall - (int)ray->x_wall;
	ray->x_texture = (int)(ray->x_wall * (double)texture->width);
	if (ray->vertical_wall_hit == true && ray->y_ray_dir > 0)
		ray->x_texture = data->text_arr[direction]->width - ray->x_texture - 1;
	if (ray->vertical_wall_hit == false && ray->x_ray_dir < 0)
		ray->x_texture = data->text_arr[direction]->width - ray->x_texture - 1;
}

void	put_stripe(t_data *data, int x, int y, int dir)
{
	mlx_texture_t	*text;
	double			tex_p;
	double			step;
	uint32_t		cl;

	text = data->text_arr[dir];
	step = (double)text->height / (double)data->line_height;
	tex_p = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * step;
	calculate_x_wall(data, dir);
	while (y < data->draw_end)
	{
		cl = data->pixels[dir][(int)tex_p * text->width + data->ray->x_texture];
		mlx_put_pixel(data->img, x, y, cl);
		tex_p += step;
		y++;
	}
}

void	draw_line(t_data *data, int x)
{
	int	y;

	y = 0;
	calculate_draw_vars(data);
	while (y < data->draw_start)
		mlx_put_pixel(data->img, x, y++, get_floor_ceiling_rgba(data->F));
	put_stripe(data, x, y, find_dir(data));
	y += data->draw_end - data->draw_start;
	while (y < HEIGHT)
		mlx_put_pixel(data->img, x, y++, get_floor_ceiling_rgba(data->C));
}
