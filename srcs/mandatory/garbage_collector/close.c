/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:06:58 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/09 16:06:58 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_map(t_map *map)
{
	if (map)
	{
		if (map->map)
			free_array(&map->map);
		if (map->textures.no)
			free(map->textures.no);
		if (map->textures.so)
			free(map->textures.so);
		if (map->textures.we)
			free(map->textures.we);
		if (map->textures.ea)
			free(map->textures.ea);
	}
}

void	free_img(t_textures *textures, t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_image(mlx->mlx, textures->walls[0].texture);
	mlx_destroy_image(mlx->mlx, textures->walls[1].texture);
	mlx_destroy_image(mlx->mlx, textures->walls[2].texture);
	mlx_destroy_image(mlx->mlx, textures->walls[3].texture);
	mlx_destroy_image(mlx->mlx, textures->door.texture);
}

int	close_cub(t_cub *cub)
{
	free_map(&cub->map);
	free_img(&cub->map.textures, &cub->mlx);
	free(cub->rays);
	mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
	mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
//	mlx_destroy_display(cub->mlx.mlx);
	free(cub->mlx.mlx);
	exit(0);
}
