/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:05 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 19:00:05 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	draw_rect_filled_color(t_cub *data, t_vector_d top_left,
		t_vector_d bottom_right, int color)
{
	int	y;
	int	x;

	y = top_left.y;
	while (y < bottom_right.y)
	{
		x = top_left.x;
		while (x < bottom_right.x)
		{
			my_mlx_pixel_put(&data->mlx, x, y, color);
			x++;
		}
		y++;
	}
}
