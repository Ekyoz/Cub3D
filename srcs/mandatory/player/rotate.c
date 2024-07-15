/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:12:51 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:12:51 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_player *player, float coef)
{
	double	rot_speed;
	double	old_dir_x;

	rot_speed = 1.5f * coef;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y
		* sin(rot_speed);
	player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y * cos(rot_speed);
}

void	rotate_left(t_player *player, float coef)
{
	double	rot_speed;
	double	old_dir_x;

	rot_speed = 1.5f * coef;
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y
		* sin(-rot_speed);
	player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y
		* cos(-rot_speed);
}
