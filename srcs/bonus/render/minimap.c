/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:56:00 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/12 13:47:04 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	print_text(t_cub *cub, t_vector_d center, int size_map);
static void	render_player_arrow(t_cub *cub, t_vector_d center);
static void	render_walls(t_cub *cub, const int map[2], double tile_minimap[2],
				double tile_size);
static void	walls_loop(t_cub *cub, t_vector_d pos[2], const int player_tile[2],
				t_vector_d map_center);

void	render_map(t_cub *cub)
{
	const int			size_map = SIZE_MAP * TILE_SIZE;
	const t_vector_d	center = create_d_vect(WIDTH - size_map + TILE_SIZE * 2,
			size_map - TILE_SIZE * 2);
	int					player_tile[2];
	t_vector_d			m_cen;
	t_vector_d			pos[2];

	pos[0] = create_d_vect(center.x - size_map / 2, center.y - size_map / 2);
	pos[1] = create_d_vect(center.x + size_map / 2, center.y + size_map / 2);
	draw_rect_filled_color(cub, pos[0], pos[1], DARK_GRAY);
	m_cen = create_d_vect((pos[0].x + pos[1].x) / 2, (pos[0].y + pos[1].y) / 2);
	player_tile[0] = (int)(cub->player.pos.x / TILE_SIZE);
	player_tile[1] = (int)(cub->player.pos.y / TILE_SIZE);
	walls_loop(cub, pos, player_tile, m_cen);
	render_player_arrow(cub, center);
	print_text(cub, center, size_map);
}

static void	walls_loop(t_cub *cub, t_vector_d pos[2], const int player_tile[2],
		t_vector_d map_center)
{
	int		x;
	int		y;
	int		map[2];
	double	tiles[2];
	double	tile_size;

	y = -MAP_ZOOM / 2 - 1;
	tile_size = (double)(SIZE_MAP * TILE_SIZE) / MAP_ZOOM;
	while (++y <= MAP_ZOOM / 2)
	{
		x = -MAP_ZOOM / 2 - 1;
		while (++x <= MAP_ZOOM / 2)
		{
			map[0] = player_tile[0] + x;
			map[1] = player_tile[1] + y;
			tiles[0] = map_center.x + (map[0] - player_tile[0]) * tile_size;
			tiles[1] = map_center.y + (map[1] - player_tile[1]) * tile_size;
			if (map[0] >= 0 && map[0] < cub->map.width && map[1] >= 0
				&& map[1] < cub->map.height && tiles[0] >= pos[0].x
				&& tiles[0] <= pos[1].x - tile_size
				&& tiles[1] >= pos[0].y && tiles[1] <= pos[1].y
				- tile_size)
				render_walls(cub, map, tiles, tile_size);
		}
	}
}

static void	render_walls(t_cub *cub, const int map[2], double tile_minimap[2],
		double t_size)
{
	t_vector_d	top_left;
	t_vector_d	bottom_right;

	top_left = create_d_vect(tile_minimap[0], tile_minimap[1]);
	bottom_right = create_d_vect(top_left.x + t_size, top_left.y + t_size);
	if (cub->map.map[map[1]][map[0]] == '1')
		draw_rect_filled_color(cub, top_left, bottom_right, WHITE);
	if (cub->map.map[map[1]][map[0]] == '2'
		|| cub->map.map[map[1]][map[0]] == '4')
		draw_rect_filled_color(cub, top_left, bottom_right, RED);
	if (cub->map.map[map[1]][map[0]] == '3'
		|| cub->map.map[map[1]][map[0]] == '5')
		draw_rect_filled_color(cub, top_left, bottom_right, GREEN);
}

static void	render_player_arrow(t_cub *cub, t_vector_d center)
{
	int			i;
	double		angle;
	t_vector_d	player[3];
	t_vector_d	rotated_player[3];

	i = 0;
	angle = atan2(cub->player.dir.y, cub->player.dir.x) + M_PI / 2;
	player[0] = create_d_vect(0, -7);
	player[1] = create_d_vect(-5, 7);
	player[2] = create_d_vect(5, 7);
	while (i < 3)
	{
		rotated_player[i].x = center.x + player[i].x * cos(angle) - player[i].y
			* sin(angle);
		rotated_player[i].y = center.y + player[i].x * sin(angle) + player[i].y
			* cos(angle);
		i++;
	}
	draw_triangle_color(cub, rotated_player, RED);
}

static void	print_text(t_cub *cub, t_vector_d center, int size_map)
{
	char	*x_pos;
	char	*y_pos;

	x_pos = ft_itoa((int)cub->player.pos.x);
	y_pos = ft_itoa((int)cub->player.pos.y);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x - 20, center.y
		+ size_map / 2 + 30, WHITE, "Minimap");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x - 65, center.y
		+ size_map / 2 + 50, WHITE, "Pos: x: ");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x - 10, center.y
		+ size_map / 2 + 50, WHITE, x_pos);
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x + 25, center.y
		+ size_map / 2 + 50, WHITE, "y: ");
	mlx_string_put(cub->mlx.mlx, cub->mlx.win, center.x + 45, center.y
		+ size_map / 2 + 50, WHITE, y_pos);
	free(x_pos);
	free(y_pos);
}
