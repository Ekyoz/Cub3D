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

	if (cub->player.map == 0)
	{
		if (mouse->move.x > 100)
			rotate_right(&cub->player, -(float)mouse->move.x / ROT_SPEED_MOUSE);
		if (mouse->move.x < 100)
			rotate_left(&cub->player, (float)mouse->move.x / ROT_SPEED_MOUSE);
		mlx_mouse_hide();
		mlx_mouse_move(cub->mlx.win, WIDTH / 2, HEIGHT / 2);
	}
	else if (cub->player.map == 1)
		mlx_mouse_show();

	mouse->move.x = 0;

	cub->player.view_dst_pos.x = (cub->player.dir.x * VIEW_DIST) + cub->player.pos.x;
	cub->player.view_dst_pos.y = (cub->player.dir.y * VIEW_DIST) + cub->player.pos.y;
}

