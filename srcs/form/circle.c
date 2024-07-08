/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:59:58 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 18:59:58 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_circle_color_radius(t_cub *data, t_vector_d center, int color, int radius)
{
	t_vector_d	pos;

	for (int y = center.y - radius; y < center.y + radius; y++)
	{
		for (int x = center.x - radius; x < center.x + radius; x++)
		{
			pos.y = (center.y - y) * (center.y - y);
			pos.x = (center.x - x) * (center.x - x);
			float test = (float)(pos.x + pos.y) - (radius * radius);
			if (test < 0.0f)
				my_mlx_pixel_put(&data->mlx, x, y, color);
		}
	}
}

void	draw_circle_empty(t_cub *data, t_vector_d center, int radius, int thickness)
{
	t_vector_d	pos;

	for (int y = center.y - radius; y < center.y + radius; y++)
	{
		for (int x = center.x - radius; x < center.x + radius; x++)
		{
			pos.y = (center.y - y) * (center.y - y);
			pos.x = (center.x - x) * (center.x - x);
			float test = (float)(pos.x + pos.y) - (radius * radius);
			if (test < 0.0f && test > -(thickness * thickness))
				my_mlx_pixel_put(&data->mlx, x, y, WHITE);
		}
	}
}