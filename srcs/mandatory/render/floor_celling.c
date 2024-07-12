/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:40:03 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/02 12:40:03 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	set_floor_cell(t_cub *cub)
{
	int		floor_start;
	int		total;
	int		size;
	int		i;
	char	*dst;

	floor_start = WIDTH * (HEIGHT / 2 + cub->mouse.move.y);
	total = WIDTH * HEIGHT;
	size = cub->mlx.bits_per_pixel / 8;
	i = -1;
	while (++i < floor_start)
	{
		dst = cub->mlx.addr + i * size;
		*(unsigned int *)dst = cub->map.textures.ceiling;
	}
	i = floor_start - 1;
	while (++i < total)
	{
		dst = cub->mlx.addr + i * size;
		*(unsigned int *)dst = cub->map.textures.floor;
	}
}
