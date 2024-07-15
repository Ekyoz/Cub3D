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

#include "cub3d.h"

void	player_input(t_cub *cub, t_keyboard *keyboard, t_mouse *mouse)
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
		rotate_left(&cub->player, ROT_SPEED_KEY);
	if (keyboard->keyboard[KEY_RIGHT] == 1)
		rotate_right(&cub->player, ROT_SPEED_KEY);
	if (keyboard->keyboard[KEY_TAB] && !keyboard->prev_keyboard[KEY_TAB])
	{
		keyboard->prev_keyboard[KEY_TAB] = 1;
		cub->player.map = !cub->player.map;
	}
	mouse->move.x = 0;
	cub->player.view_dst_pos.x = (cub->player.dir.x * VIEW_DIST)
		+ cub->player.pos.x;
	cub->player.view_dst_pos.y = (cub->player.dir.y * VIEW_DIST)
		+ cub->player.pos.y;
}
