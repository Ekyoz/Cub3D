/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:45:56 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:02:04 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int update(t_cub *cub);

void clear_window(t_cub *data)
{
	int total = WIDTH * HEIGHT;
	int	size = data->mlx.bits_per_pixel / 8;

	for (int i = 0; i < total; i++)
	{
		char *dst = data->mlx.addr + i * size;
		*(unsigned int *)dst = DARK_GRAY;
	}
}

void draw_rect_filled_color(t_cub *data, t_vector_d top_left, t_vector_d bottom_right, int color)
{
	for (int y = top_left.y; y < bottom_right.y; y++)
	{
		for (int x = top_left.x; x < bottom_right.x; x++)
		{
			my_mlx_pixel_put(&data->mlx, x, y, color);
		}
	}
}

void	print_grid(t_cub *data)
{
	// Walls
	for (int y = 0; y < data->map.height; y++)
	{
		for (int x = 0; x < data->map.width; x++)
		{
			t_vector_d	top_left = {x * TILE_SIZE, y * TILE_SIZE};
			t_vector_d	bot_right = {top_left.x + TILE_SIZE, top_left.y + TILE_SIZE};
			if (data->map.map[y][x] == '1') // Walls
				draw_rect_filled_color(data, top_left, bot_right, PINK);
		}
	}
}

void draw_circle(t_cub *data, t_vector_d center)
{
	t_vector_d pos;
	int radius = 2;

	for (int y = center.y - radius; y < center.y + radius; y++)
	{
		for (int x = center.x - radius; x < center.x + radius; x++)
		{
			pos.y = (center.y - y) * (center.y - y);
			pos.x = (center.x - x) * (center.x - x);
			if ((float)(pos.x + pos.y) - (radius * radius) < 0.1f)
				my_mlx_pixel_put(&data->mlx, x, y, PINK);
		}
	}
}

void loop(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 2, 1L << 0, key_press, &cub->keyboard);
	mlx_hook(cub->mlx.win, 3, 1L << 1, key_release, &cub->keyboard);
	mlx_hook(cub->mlx.win, 4, 1L << 2, mouse_hook, &cub->mouse);
	mlx_hook(cub->mlx.win, 5, 1L << 3, mouse_release, &cub->mouse);
	mlx_hook(cub->mlx.win, 6, 1L << 6, update_mouse_pos, &cub->mouse);
	mlx_hook(cub->mlx.win, 17, 1L << 0, (int (*)()) exit, NULL); // Ferme la fenetre avec la croix
	mlx_loop_hook(cub->mlx.mlx, update, cub);
	mlx_loop(cub->mlx.mlx);
}

void  set_grid_cell(t_cub *cub, int x, int y)
{
	// Converting pixel coordinates into tab coordinates
	t_vector_d tab_pos = {
			x / TILE_SIZE, // x
			y / TILE_SIZE // y
	};

	// Checking out of range coordinates
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;

	// Changing cell value according to mouse button
	if (cub->mouse.button == LMB && cub->mouse.pressed == 1)
		cub->map.map[tab_pos.y][tab_pos.x] = '1';
	else if (cub->mouse.button == RMB && cub->mouse.pressed == 1)
		cub->map.map[tab_pos.y][tab_pos.x] = '0';
}

static int update(t_cub *cub)
{
	player_input(cub, &cub->keyboard, &cub->mouse);

	if (cub->player.map)
	{
		clear_window(cub);
//		set_grid_cell(cub, cub->mouse.pos.x, cub->mouse.pos.y); // Set walls
		print_grid(cub); // Show walls
		bresenham(cub, vector_f_to_d(cub->player.pos), vector_f_to_d(cub->player.dir), YELLOW);
		draw_circle(cub, vector_f_to_d(cub->player.pos)); // Player visualization
	}

	create_rays(cub);
	rays_collisions(cub);
	if (!cub->player.map)
	{
		set_floor_cell(cub);
		rays_render(cub);
	}

	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	return (0);
}