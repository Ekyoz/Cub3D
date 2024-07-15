/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:24:48 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/09 17:11:52 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	*init_color(t_pcub *cub)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (!color)
	{
		print_free_exit(ERROR_MALLOC_INIT, cub);
	}
	color->r_ceiling = 0;
	color->g_ceiling = 0;
	color->b_ceiling = 0;
	color->r_floor = 0;
	color->g_floor = 0;
	color->b_floor = 0;
	return (color);
}

static char	**put_cubmap_in_map(t_pcub *cub)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (cub->y_max_size + 1));
	if (!map)
		print_free_exit(ERROR_MALLOC_INIT, cub);
	while (i < cub->y_max_size)
	{
		map[i] = ft_strdup(cub->map[i]);
		if (!map[i])
			print_free_exit(ERROR_MALLOC_INIT, cub);
		i++;
	}
	map[cub->y_max_size] = NULL;
	return (map);
}

t_map	init_map(void)
{
	t_map	map;

	map.map = NULL;
	map.width = 0;
	map.height = 0;
	map.textures.no = NULL;
	map.textures.so = NULL;
	map.textures.we = NULL;
	map.textures.ea = NULL;
	map.textures.floor = 0;
	map.textures.ceiling = 0;
	return (map);
}

t_pcub	*init_cub(void)
{
	t_pcub	*cub;

	cub = malloc(sizeof(t_pcub));
	if (!cub)
	{
		print_free_exit(ERROR_MALLOC_INIT, cub);
	}
	cub->color = init_color(cub);
	cub->counttexture = 0;
	cub->linetexture = 0;
	cub->linemap = 0;
	cub->x_max_size = 0;
	cub->notexture = NULL;
	cub->sotexture = NULL;
	cub->eatexture = NULL;
	cub->wetexture = NULL;
	cub->map = NULL;
	cub->filefd = -1;
	return (cub);
}

void	put_cub_in_map(t_pcub **cub, t_map *map)
{
	map->map = put_cubmap_in_map((*cub));
	map->width = (*cub)->x_max_size;
	map->height = (*cub)->y_max_size;
	map->textures.no = ft_strdup((*cub)->notexture);
	map->textures.so = ft_strdup((*cub)->sotexture);
	map->textures.we = ft_strdup((*cub)->wetexture);
	map->textures.ea = ft_strdup((*cub)->eatexture);
	map->textures.floor = (*cub)->color->floor;
	map->textures.ceiling = (*cub)->color->ceiling;
	free_cub(cub);
}
