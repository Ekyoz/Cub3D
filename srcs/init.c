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

#include "cube3d.h"

int init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (1);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "Cub3D");
	if (mlx->win == NULL)
		return (1);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img == NULL)
		return (1);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length, &mlx->endian);
	if (mlx->addr == NULL)
		return (1);
	return (0);
}

int init_rays(t_cub *cub)
{
	cub->rays_nb = WIDTH;
	cub->rays = malloc(sizeof(t_ray) * cub->rays_nb);
	if (cub->rays == NULL)
		return 1;
	return 0;
}

int init_mouse(t_mouse *mouse, void *win)
{
	mouse->pos.x = WIDTH / 2;
	mouse->pos.y = HEIGHT / 2;
	mouse->move.x = 0;
	mouse->move.y = 0;
	mlx_mouse_hide();
	mlx_mouse_move(win, mouse->pos.x, mouse->pos.y);
	return 0;
}