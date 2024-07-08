/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:56:00 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 19:17:20 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void render_map(t_cub *cub)
{
	const int size_map = 200;
	const t_vector_d center = create_d_vect(WIDTH - 10 - size_map/2, size_map/2 + 10);

	t_vector_d tl = create_d_vect(WIDTH - 10 - size_map, 10);
	t_vector_d br = create_d_vect(WIDTH - 10, size_map + 10);

	draw_rounded_rect_filled_color(cub, tl, br, 10, DARK_GRAY);
	draw_rounded_rect_color(cub, tl, br, 5, WHITE);
	t_vector_d player[3];
	player[0] = create_d_vect(center.x, center.y - 5);
	player[1] = create_d_vect(center.x - 5, center.y + 5);
	player[2] = create_d_vect(center.x + 5, center.y + 5);
	draw_triangle_color(cub, player, WHITE);

	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, WIDTH - 10 - size_map/2-20, size_map + 30, WHITE, "Minimap");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, WIDTH - 10 - size_map/2 - 60, size_map + 50, WHITE, "Pos: x: ");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, WIDTH - 10 - size_map/2 - 5, size_map + 50, WHITE, ft_itoa((int)cub->player.pos.x));
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, WIDTH - 10 - size_map/2 + 20, size_map + 50, WHITE, "y: ");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, WIDTH - 10 - size_map/2 + 40, size_map + 50, WHITE, ft_itoa((int)cub->player.pos.y));
}