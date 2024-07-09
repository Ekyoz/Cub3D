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
	const int size_map = SIZE_MAP * TILE_SIZE;
	const t_vector_d center = create_d_vect(WIDTH - size_map + TILE_SIZE*2, size_map - TILE_SIZE*2);

	t_vector_d tl = create_d_vect(center.x - size_map/2, center.y - size_map/2);
	t_vector_d br = create_d_vect(center.x + size_map/2, center.y + size_map/2);

	draw_rounded_rect_filled_color(cub, tl, br, 10, DARK_GRAY);

	// Taille d'une tuile sur la minimap
	double tile_size = (double)size_map / MAP_ZOOM;

	// Centre de la minimap
	t_vector_d map_center = create_d_vect(
			(tl.x + br.x) / 2,
			(tl.y + br.y) / 2
	);

	// Position du joueur en coordonnées de tuiles
	int player_tile_x = (int)(cub->player.pos.x / TILE_SIZE);
	int player_tile_y = (int)(cub->player.pos.y / TILE_SIZE);

	// Afficher la zone autour du joueur
	for (int y = -MAP_ZOOM / 2; y <= MAP_ZOOM / 2; y++) {
		for (int x = -MAP_ZOOM / 2; x <= MAP_ZOOM / 2; x++) {
			int map_x = player_tile_x + x;
			int map_y = player_tile_y + y;

			// Calculer les coordonnées de la tuile sur la minimap
			double tile_x_minimap = map_center.x + (map_x - player_tile_x) * tile_size;
			double tile_y_minimap = map_center.y + (map_y - player_tile_y) * tile_size;

			// Vérifier que les coordonnées sont dans les limites de la carte et de la minimap
			if (map_x >= 0 && map_x < cub->map.width && map_y >= 0 && map_y < cub->map.height
				&& tile_x_minimap >= tl.x && tile_x_minimap <= br.x - tile_size
				&& tile_y_minimap >= tl.y && tile_y_minimap <= br.y - tile_size) {
				t_vector_d top_left = create_d_vect(
						tile_x_minimap,
						tile_y_minimap
				);
				t_vector_d bottom_right = create_d_vect(
						top_left.x + tile_size,
						top_left.y + tile_size
				);

				if (cub->map.map[map_y][map_x] == '1') {
					draw_rect_filled_color(cub, top_left, bottom_right, WHITE);
				} else {
					draw_rect_filled_color(cub, top_left, bottom_right, DARK_GRAY);
				}
			}
		}
	}
	draw_rounded_rect_color(cub, tl, br, 5, BLACK);

	double angle = atan2(cub->player.dir.y, cub->player.dir.x) + M_PI / 2;

	// Coordonnées initiales du triangle avant rotation
	t_vector_d player[3];
	player[0] = create_d_vect(0, -7);
	player[1] = create_d_vect(-5, 7);
	player[2] = create_d_vect(5, 7);

	// Applique la rotation et la translation au centre
	t_vector_d rotated_player[3];
	for (int i = 0; i < 3; i++) {
		rotated_player[i].x = center.x + player[i].x * cos(angle) - player[i].y * sin(angle);
		rotated_player[i].y = center.y + player[i].x * sin(angle) + player[i].y * cos(angle);
	}
	draw_triangle_color(cub, rotated_player, RED);

//
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x - 20, center.y + size_map / 2 + 30, WHITE, "Minimap");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x - 65, center.y + size_map / 2 + 50, WHITE, "Pos: x: ");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x - 10, center.y + size_map / 2 + 50, WHITE, ft_itoa((int)cub->player.pos.x));
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x + 25, center.y + size_map / 2 + 50, WHITE, "y: ");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x + 45, center.y + size_map / 2 + 50, WHITE, ft_itoa((int)cub->player.pos.y));
}