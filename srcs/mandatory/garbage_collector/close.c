/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:06:58 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/15 18:51:26 by atresall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (textures->walls[0].texture)
		mlx_destroy_image(mlx->mlx, textures->walls[0].texture);
	if (textures->walls[1].texture)
		mlx_destroy_image(mlx->mlx, textures->walls[1].texture);
	if (textures->walls[2].texture)
		mlx_destroy_image(mlx->mlx, textures->walls[2].texture);
	if (textures->walls[3].texture)
		mlx_destroy_image(mlx->mlx, textures->walls[3].texture);
}

int	close_cub(t_cub *cub, char *str, int err_code)
{
	free_map(&cub->map);
	free(cub->rays);
	if (cub->mlx.mlx)
	{
		free_img(&cub->map.textures, &cub->mlx);
		if (cub->mlx.win)
		{
			mlx_clear_window(cub->mlx.mlx, cub->mlx.win);
			mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
		}
		mlx_destroy_display(cub->mlx.mlx);
		free(cub->mlx.mlx);
	}
	if (str)
		printf("\n\n\033[31m==%s==\033[0m\n\n", str);
	exit(err_code);
}
