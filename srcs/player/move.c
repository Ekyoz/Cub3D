/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:12:45 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 14:42:51 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static float coll_x(t_vector_f dir);
static float coll_y(t_vector_f dir);

void move_forward(t_cub *cub)
{
	t_vector_f new_pos = {
			cub->player.dir.x * MOVE_SPEED,
			cub->player.dir.y * MOVE_SPEED
	};

	if (!is_colliding_cell(cub, cub->player.pos.x + new_pos.x + coll_x(cub->player.dir), cub->player.pos.y))
		cub->player.pos.x += new_pos.x;

	if (!is_colliding_cell(cub, cub->player.pos.x, cub->player.pos.y + new_pos.y +
			coll_y(cub->player.dir)))
		cub->player.pos.y += new_pos.y;
}

void move_backward(t_cub *cub)
{
	t_vector_f new_pos = {
			cub->player.dir.x * MOVE_SPEED,
			cub->player.dir.y * MOVE_SPEED
	};

	if (!is_colliding_cell(cub, cub->player.pos.x - new_pos.x - coll_x(cub->player.dir), cub->player.pos.y))
		cub->player.pos.x -= new_pos.x;

	if (!is_colliding_cell(cub, cub->player.pos.x, cub->player.pos.y - new_pos.y - coll_y(cub->player.dir)))
		cub->player.pos.y -= new_pos.y;
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

	if (!is_colliding_cell(cub, cub->player.pos.x + new_pos.x, cub->player.pos.y))
		cub->player.pos.x += new_pos.x;

	if (!is_colliding_cell(cub, cub->player.pos.x, cub->player.pos.y + new_pos.y))
		cub->player.pos.y += new_pos.y;
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

	if (!is_colliding_cell(cub, cub->player.pos.x + new_pos.x, cub->player.pos.y))
		cub->player.pos.x += new_pos.x;

	if (!is_colliding_cell(cub, cub->player.pos.x, cub->player.pos.y + new_pos.y))
		cub->player.pos.y += new_pos.y;
}

static float coll_x(t_vector_f dir)
{
	if (dir.x > 0)
		return 5.0f;
	else if (dir.x < 0)
		return -5.0f;
	return 0.0f;
}

static float coll_y(t_vector_f dir)
{
	if (dir.y > 0)
		return 5.0f;
	else if (dir.y < 0)
		return -5.0f;
	return 0.0f;
}

