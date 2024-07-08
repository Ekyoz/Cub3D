/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:12:00 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 15:11:51 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int init_tab(t_map *map)
{
	// Setting initial tab dimensions
	map->height = 20;
	map->width = 20;
	// Allocating tab
	map->map = malloc(sizeof(char *) * map->height);
	if (map->map == NULL) // Checking allocation error
		return (1);

	for (int y = 0; y < map->height; y++)
	{
		map->map[y] = malloc(sizeof(char) * map->width);
		if (map->map[y] == NULL) // Checking allocation error
			return (1);

		// Putting values in tab
		for (int x = 0; x < map->width; x++)
		{
			if (y == 0 || y == map->height - 1 || x == 0 || x == map->width - 1)
			{
				map->map[y][x] = '1'; // Setting the borders to 1
			}
			else
			{
				map->map[y][x] = '0'; // Setting the inner cells to 0
			}
		}
	}
	return (0);
}

int main()
{
	t_cub cub;

	init_tab(&cub.map);

	cub.map.ceiling = LIGHT_BLUE;
	cub.map.floor = DARK_GRAY;


	cub.map.NO = "./assets/walls/wood.xpm";
	cub.map.SO = "./assets/walls/blue_bricks.xpm";
	cub.map.WE = "./assets/walls/red_brick.xpm";
	cub.map.EA = "./assets/walls/grey_brick.xpm";
	cub.player.pos.x = 5 * TILE_SIZE + TILE_SIZE / 4;
	cub.player.pos.y = 5 * TILE_SIZE + TILE_SIZE / 4;

	cub.player.dir.x = 1.0f;
	cub.player.dir.y = 0.0f;
	cub.player.map = 0;


	if (init_mlx(&cub.mlx) == 1)
		exit(1);
	if (init_rays(&cub) == 1)
		exit(1);
	if (init_input(&cub.mouse, &cub.keyboard, cub.mlx.win) == 1)
		exit(1);
	if (init_texture(&cub) == 1)
		exit(1);

	loop(&cub);
}