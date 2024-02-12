/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aolde-mo <aolde-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:49:09 by aolde-mo          #+#    #+#             */
/*   Updated: 2024/02/11 16:11:29 by aolde-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

#include <math.h>

#define MOVE_SPEED 0.11
#define ROT_SPD 0.0625

#define POV_MIN 0.2
#define POV_MAX 1.0

#define MIN_DIST 0.125

static void	rotate(t_data *data, t_player *p, t_movement movement)
{
	double	tmp_x_dir;
	double	tmp_x_plane;

	tmp_x_dir = p->x_dir;
	tmp_x_plane = p->x_plane;
	if (movement == ROTATE_LEFT)
	{
		p->x_dir = p->x_dir * cos(-ROT_SPD) - p->y_dir * sin(-ROT_SPD);
		p->y_dir = tmp_x_dir * sin(-ROT_SPD) + p->y_dir * cos(-ROT_SPD);
		p->x_plane = p->x_plane * cos(-ROT_SPD) - p->y_plane * sin(-ROT_SPD);
		p->y_plane = tmp_x_plane * sin(-ROT_SPD) + p->y_plane * cos(-ROT_SPD);
	}
	if (movement == ROTATE_RIGHT)
	{
		p->x_dir = p->x_dir * cos(ROT_SPD) - p->y_dir * sin(ROT_SPD);
		p->y_dir = tmp_x_dir * sin(ROT_SPD) + p->y_dir * cos(ROT_SPD);
		p->x_plane = p->x_plane * cos(ROT_SPD) - p->y_plane * sin(ROT_SPD);
		p->y_plane = tmp_x_plane * sin(ROT_SPD) + p->y_plane * cos(ROT_SPD);
	}
	raycasting(data);
}

static void	move_forward_backward(t_data *data, t_movement movement)
{
	t_player	*player;
	double		tmp_x;
	double		tmp_y;
	int			sign;

	player = data->player;
	if (movement == FORWARD)
		sign = 1;
	if (movement == BACKWARD)
		sign = -1;
	tmp_x = player->x_pos + player->x_dir * MOVE_SPEED * sign;
	tmp_y = player->y_pos + player->y_dir * MOVE_SPEED * sign;
	if (data->map[(int)tmp_y][(int)tmp_x] == WALL)
		return ;
	player->x_pos = tmp_x;
	player->y_pos = tmp_y;
	raycasting(data);
}

static void	move_left_right(t_data *data, t_movement movement)
{
	t_player	*player;
	double		tmp_x;
	double		tmp_y;

	player = data->player;
	if (movement == LEFT)
	{
		tmp_x = player->x_pos + player->y_dir * MOVE_SPEED;
		tmp_y = player->y_pos - player->x_dir * MOVE_SPEED;
	}
	if (movement == RIGHT)
	{
		tmp_x = player->x_pos - player->y_dir * MOVE_SPEED;
		tmp_y = player->y_pos + player->x_dir * MOVE_SPEED;
	}
	if (data->map[(int)tmp_y][(int)tmp_x] == WALL)
		return ;
	player->x_pos = tmp_x;
	player->y_pos = tmp_y;
	raycasting(data);
}

void	key_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate(data, data->player, ROTATE_LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate(data, data->player, ROTATE_RIGHT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		close_mlx(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_forward_backward(data, FORWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_forward_backward(data, BACKWARD);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left_right(data, LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_left_right(data, RIGHT);
}
