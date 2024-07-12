/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:05:06 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/11 17:05:06 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static float	coll_x(t_vector_f dir);
static float	coll_y(t_vector_f dir);

void	move_forward(t_cub *cub)
{
	t_vector_f	new_pos;

	new_pos = create_f_vect(cub->player.dir.x * MOVE_SPEED, cub->player.dir.y
			* MOVE_SPEED);
	if (!is_colliding_cell(cub, cub->player.pos.x + new_pos.x
			+ coll_x(cub->player.dir), cub->player.pos.y, 1))
		cub->player.pos.x += new_pos.x;
	if (!is_colliding_cell(cub, cub->player.pos.x, cub->player.pos.y + new_pos.y
			+ coll_y(cub->player.dir), 1))
		cub->player.pos.y += new_pos.y;
}

void	move_backward(t_cub *cub)
{
	t_vector_f	new_pos;

	new_pos = create_f_vect(cub->player.dir.x * MOVE_SPEED, cub->player.dir.y
			* MOVE_SPEED);
	if (!is_colliding_cell(cub, cub->player.pos.x - new_pos.x
			- coll_x(cub->player.dir), cub->player.pos.y, 1))
		cub->player.pos.x -= new_pos.x;
	if (!is_colliding_cell(cub, cub->player.pos.x, cub->player.pos.y - new_pos.y
			- coll_y(cub->player.dir), 1))
		cub->player.pos.y -= new_pos.y;
}

static float	coll_x(t_vector_f dir)
{
	if (dir.x > 0)
		return (5.0f);
	else if (dir.x < 0)
		return (-5.0f);
	return (0.0f);
}

static float	coll_y(t_vector_f dir)
{
	if (dir.y > 0)
		return (5.0f);
	else if (dir.y < 0)
		return (-5.0f);
	return (0.0f);
}
