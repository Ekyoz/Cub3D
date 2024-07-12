/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:52:27 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/11 14:52:27 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	move_forward(t_cub *cub)
{
	t_vector_f	new_pos;

	new_pos = create_f_vect(cub->player.dir.x * MOVE_SPEED, cub->player.dir.y
			* MOVE_SPEED);
	cub->player.pos.x += new_pos.x;
	cub->player.pos.y += new_pos.y;
}

void	move_backward(t_cub *cub)
{
	t_vector_f	new_pos;

	new_pos = create_f_vect(cub->player.dir.x * MOVE_SPEED, cub->player.dir.y
			* MOVE_SPEED);
	cub->player.pos.x -= new_pos.x;
	cub->player.pos.y -= new_pos.y;
}
