/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:37:53 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 15:37:53 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_game(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	if (cub->mlx.mlx == NULL)
		close_cub(&cub, MLX_INIT, 1);
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	if (cub->mlx.win == NULL)
		close_cub(&cub, MLX_WIN, 1);
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, WIDTH, HEIGHT);
	if (cub->mlx.img == NULL)
		close_cub(&cub, MLX_IMG, 1);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &cub->mlx.bits_per_pixel,
			&cub->mlx.line_length, &cub->mlx.endian);
	if (cub->mlx.addr == NULL)
		close_cub(&cub, MLX_IMG, 1);
	cub->rays_nb = WIDTH;
	cub->rays = malloc(sizeof(t_ray) * cub->rays_nb);
	if (cub->rays == NULL)
		close_cub(&cub, MLX_MALLOC_RAYS, 1);
	return (0);
}

int	init_input(t_mouse *mouse, t_keyboard *keyboard)
{
	mouse->pos.x = WIDTH / 2;
	mouse->pos.y = HEIGHT / 2;
	mouse->move.x = 0;
	mouse->move.y = 0;
	mouse->pressed = 0;
	keyboard->keyboard[KEY_W] = 0;
	keyboard->keyboard[KEY_A] = 0;
	keyboard->keyboard[KEY_S] = 0;
	keyboard->keyboard[KEY_D] = 0;
	keyboard->keyboard[KEY_E] = 0;
	keyboard->prev_keyboard[KEY_E] = 0;
	keyboard->keyboard[KEY_UP] = 0;
	keyboard->keyboard[KEY_DOWN] = 0;
	keyboard->keyboard[KEY_LEFT] = 0;
	keyboard->keyboard[KEY_RIGHT] = 0;
	keyboard->keyboard[KEY_TAB] = 0;
	keyboard->keyboard[KEY_ESC] = 0;
	return (0);
}

static int	init_player_2(t_cub *cub, char cell, int x, int y)
{
	if (cell == 'N' || cell == 'S' || cell == 'W' || cell == 'E')
	{
		cub->player.pos.x = (float)x * TILE_SIZE + TILE_SIZE / 2;
		cub->player.pos.y = (float)y * TILE_SIZE + TILE_SIZE / 2;
		cub->map.map[y][x] = '0';
		if (cell == 'N' || cell == 'S')
		{
			cub->player.dir.x = 0.0f;
			if (cell == 'N')
				cub->player.dir.y = -1.0f;
			if (cell == 'S')
				cub->player.dir.y = 1.0f;
		}
		if (cell == 'W' || cell == 'E')
		{
			cub->player.dir.y = 0.0f;
			if (cell == 'W')
				cub->player.dir.x = -1.0f;
			if (cell == 'E')
				cub->player.dir.x = 1.0f;
		}
		return (0);
	}
	return (1);
}

int	init_player(t_cub *cub)
{
	int		x;
	int		y;
	char	cell;

	x = -1;
	cub->player.map = 0;
	while (++x < cub->map.width - 1)
	{
		y = -1;
		while (++y < cub->map.height - 1)
		{
			cell = cub->map.map[y][x];
			if (init_player_2(cub, cell, x, y) == 0)
				return (0);
		}
	}
	return (1);
}

int	init_sprites(t_cub *cub)
{
	cub->map.textures.walls[0] = load_texture(cub, cub->map.textures.so);
	cub->map.textures.walls[1] = load_texture(cub, cub->map.textures.we);
	cub->map.textures.walls[2] = load_texture(cub, cub->map.textures.no);
	cub->map.textures.walls[3] = load_texture(cub, cub->map.textures.ea);
	cub->map.textures.door = load_texture(cub, "./assets/door.xpm");
	return (0);
}
