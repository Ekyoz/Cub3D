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

void player_input(t_cub *cub, t_keyboard *keyboard, t_mouse *mouse)
{
	printf("Player pos: %f %f\n", cub->player.pos.x, cub->player.pos.y);
	if (keyboard->keyboard[KEY_W] == 1)
		move_forward(cub);
	if (keyboard->keyboard[KEY_S] == 1)
		move_backward(cub);
	if (keyboard->keyboard[KEY_D] == 1)
		move_right(cub);
	if (keyboard->keyboard[KEY_A] == 1)
		move_left(cub);
	if (keyboard->keyboard[KEY_LEFT] == 1)
		rotate_left(&cub->player,ROT_SPEED_KEY);
	if (keyboard->keyboard[KEY_RIGHT] == 1)
		rotate_right(&cub->player, ROT_SPEED_KEY);
	if (keyboard->keyboard[KEY_TAB] == 1)
	{
		if (cub->player.map == 1)
			cub->player.map = 0;
		else
			cub->player.map = 1;
	}

	if (mouse->move.x > 100)
		rotate_right(&cub->player, -(float)mouse->move.x / ROT_SPEED_MOUSE);
	if (mouse->move.x < 100)
		rotate_left(&cub->player, (float)mouse->move.x / ROT_SPEED_MOUSE);
	mlx_mouse_move(cub->mlx.win, WIDTH / 2, HEIGHT / 2);

	mouse->move.x = 0;

	cub->player.view_dst_pos.x = (cub->player.dir.x * VIEW_DIST) + cub->player.pos.x;
	cub->player.view_dst_pos.y = (cub->player.dir.y * VIEW_DIST) + cub->player.pos.y;
}

int		is_colliding_cell(t_cub *cub, float x, float y)
{
	t_vector_d	cell;

	if (!is_in_map(cub, create_d_vect(x, y)))
		return (0);
	cell.x = x / TILE_SIZE;
	cell.y = y / TILE_SIZE;
	if (cub->map.map[cell.y][cell.x] == '1') // Wall
		return (1);
	return (0);
}