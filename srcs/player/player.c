/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:30:55 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:30:55 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void toggle_door(t_cub *cub);

void player_input(t_cub *cub, t_keyboard *keyboard, t_mouse *mouse)
{
	if (keyboard->keyboard[KEY_W] == 1 || keyboard->keyboard[KEY_UP])
		move_forward(cub);
	if (keyboard->keyboard[KEY_S] == 1 || keyboard->keyboard[KEY_DOWN])
		move_backward(cub);
	if (keyboard->keyboard[KEY_D] == 1)
		move_right(cub);
	if (keyboard->keyboard[KEY_A] == 1)
		move_left(cub);
	if (keyboard->keyboard[KEY_LEFT] == 1)
		rotate_left(&cub->player,ROT_SPEED_KEY);
	if (keyboard->keyboard[KEY_RIGHT] == 1)
		rotate_right(&cub->player, ROT_SPEED_KEY);
	if (keyboard->keyboard[KEY_E] && !keyboard->prev_keyboard[KEY_E])
	{
		keyboard->prev_keyboard[KEY_E] = 1;
		toggle_door(cub);
	}

	if (keyboard->keyboard[KEY_TAB] && !keyboard->prev_keyboard[KEY_TAB])
	{
		keyboard->prev_keyboard[KEY_TAB] = 1;
		cub->player.map = !cub->player.map;
	}

	if (!cub->player.map)
	{
		if (mouse->move.x > 100)
			rotate_right(&cub->player, -(float)mouse->move.x / ROT_SPEED_MOUSE);
		if (mouse->move.x < 100)
			rotate_left(&cub->player, (float)mouse->move.x / ROT_SPEED_MOUSE);
//		mlx_mouse_hide(cub->mlx.mlx, cub->mlx.win);
//		mlx_mouse_move(cub->mlx.mlx, cub->mlx.win, WIDTH / 2, HEIGHT / 2);
	}
//	else if (cub->player.map)
//		mlx_mouse_show(cub->mlx.mlx, cub->mlx.win);
	mouse->move.x = 0;

	cub->player.view_dst_pos.x = (cub->player.dir.x * VIEW_DIST) + cub->player.pos.x;
	cub->player.view_dst_pos.y = (cub->player.dir.y * VIEW_DIST) + cub->player.pos.y;
}

void toggle_door(t_cub *cub)
{
	t_vector_d cell;

	cell.x = cub->player.pos.x + (cub->player.dir.x * TILE_SIZE);
	cell.y = cub->player.pos.y + (cub->player.dir.y * TILE_SIZE);

	if (cell.x < 0 || cell.x > WIDTH - 1)
		return ;
	if (cell.y < 0 || cell.y > HEIGHT - 1)
		return ;

	cell.x /= TILE_SIZE;
	cell.y /= TILE_SIZE;
	if (cub->map.map[cell.y][cell.x] == '2')
		cub->map.map[cell.y][cell.x] = '3';
	else if (cub->map.map[cell.y][cell.x] == '3')
		cub->map.map[cell.y][cell.x] = '2';

	if (cub->map.map[cell.y][cell.x] == '4')
		cub->map.map[cell.y][cell.x] = '5';
	else if (cub->map.map[cell.y][cell.x] == '5')
		cub->map.map[cell.y][cell.x] = '4';
}
