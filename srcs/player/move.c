/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:12:45 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:12:45 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void move_forward(t_cub *cub)
{
	t_vector_f new_pos = {
			cub->player.dir.x * MOVE_SPEED,
			cub->player.dir.y * MOVE_SPEED
	};

	t_vector_f *p_pos = &cub->player.pos; // Reference to player pos

// Check collision on X coordinate
	if (!is_colliding_cell(cub, p_pos->x + new_pos.x, p_pos->y))
		p_pos->x += new_pos.x;

// Check collision on Y coordinate
	if (!is_colliding_cell(cub, p_pos->x, p_pos->y + new_pos.y))
		p_pos->y += new_pos.y;
}

void move_backward(t_cub *cub)
{
	t_vector_f new_pos = {
			cub->player.dir.x * MOVE_SPEED,
			cub->player.dir.y * MOVE_SPEED
	};

	t_vector_f *p_pos = &cub->player.pos; // Reference to player pos

// Check collision on X coordinate
	if (!is_colliding_cell(cub, p_pos->x + new_pos.x, p_pos->y))
		p_pos->x -= new_pos.x;

// Check collision on Y coordinate
	if (!is_colliding_cell(cub, p_pos->x, p_pos->y - new_pos.y))
		p_pos->y -= new_pos.y;
}

void move_left(t_cub *cub)
{
	t_vector_f new_dir = {
			cub->player.dir.x * cos(-PI_2) - cub->player.dir.y * sin(-PI_2),
			cub->player.dir.x * sin(-PI_2) + cub->player.dir.y * cos(-PI_2)
	};

	t_vector_f new_pos = {
			new_dir.x * MOVE_SPEED,
			new_dir.y * MOVE_SPEED
	};

	t_vector_f *p_pos = &cub->player.pos; // Reference to player pos

// Check collision on X coordinate
	if (!is_colliding_cell(cub, p_pos->x + new_pos.x, p_pos->y))
		p_pos->x += new_pos.x;

// Check collision on Y coordinate
	if (!is_colliding_cell(cub, p_pos->x, p_pos->y + new_pos.y))
		p_pos->y += new_pos.y;
}

void move_right(t_cub *cub)
{
	t_vector_f new_dir = {
			cub->player.dir.x * cos(PI_2) - cub->player.dir.y * sin(PI_2),
			cub->player.dir.x * sin(PI_2) + cub->player.dir.y * cos(PI_2)
	};

	t_vector_f new_pos = {
			new_dir.x * MOVE_SPEED,
			new_dir.y * MOVE_SPEED
	};

	t_vector_f *p_pos = &cub->player.pos; // Reference to player pos

// Check collision on X coordinate
	if (!is_colliding_cell(cub, p_pos->x + new_pos.x, p_pos->y))
		p_pos->x += new_pos.x;

// Check collision on Y coordinate
	if (!is_colliding_cell(cub, p_pos->x, p_pos->y + new_pos.y))
		p_pos->y += new_pos.y;
}