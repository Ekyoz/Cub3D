/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:43:19 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 15:43:19 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int is_in_map(t_cub *cub, t_vector_d pos)
{
	if (pos.x < 0 || pos.x > cub->map.width - 1)
		return (0);
	if (pos.y < 0 || pos.y > cub->map.height - 1)
		return (0);
	return (1);
}

int		is_colliding_cell(t_cub *cub, float x, float y, int plain_cell)
{
	t_vector_d	cell;

	set_vector_d(&cell, x / TILE_SIZE, y / TILE_SIZE);
	if (!is_in_map(cub, create_d_vect(cell.x, cell.y)))
		return (0);
	if (cub->map.map[cell.y][cell.x] == '1') // Wall
		return (1);
	if (cub->map.map[cell.y][cell.x] == '2')
	{
		if (plain_cell || (int)y % TILE_SIZE == TILE_SIZE / 2)
			return (1);
	}
	if (cub->map.map[cell.y][cell.x] == '4')
	{
		if (plain_cell || (int)x % TILE_SIZE == TILE_SIZE / 2)
			return (1);
	}
	return (0);
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

void  set_grid_cell(t_cub *cub, int x, int y)
{
	t_vector_d tab_pos = {
			x / TILE_SIZE, // x
			y / TILE_SIZE // y
	};

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return;
	if (tab_pos.x < 0 || tab_pos.x >= cub->map.width || tab_pos.y < 0 || tab_pos.y >= cub->map.height)
		return;

	if (cub->mouse.button == LMB && cub->mouse.pressed == 1)
		cub->map.map[tab_pos.y][tab_pos.x] = '1';
	else if (cub->mouse.button == RMB && cub->mouse.pressed == 1)
		cub->map.map[tab_pos.y][tab_pos.x] = '0';
}

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