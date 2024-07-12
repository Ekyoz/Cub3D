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

#include "cub3d.h"

void	move_left(t_cub *cub)
{
	t_vector_f	new_dir;
	t_vector_f	new_pos;

	new_dir = create_f_vect(cub->player.dir.x * cos(-PI_2) - cub->player.dir.y
			* sin(-PI_2), cub->player.dir.x * sin(-PI_2) + cub->player.dir.y
			* cos(-PI_2));
	new_pos = create_f_vect(new_dir.x * MOVE_SPEED, new_dir.y * MOVE_SPEED);
	cub->player.pos.x += new_pos.x;
	cub->player.pos.y += new_pos.y;
}

void	move_right(t_cub *cub)
{
	t_vector_f	new_dir;
	t_vector_f	new_pos;

	new_dir = create_f_vect(cub->player.dir.x * cos(PI_2) - cub->player.dir.y
			* sin(PI_2), cub->player.dir.x * sin(PI_2) + cub->player.dir.y
			* cos(PI_2));
	new_pos = create_f_vect(new_dir.x * MOVE_SPEED, new_dir.y * MOVE_SPEED);
	cub->player.pos.x += new_pos.x;
	cub->player.pos.y += new_pos.y;
}
