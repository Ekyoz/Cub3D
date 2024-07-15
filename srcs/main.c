/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:57:32 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/15 19:22:23 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_strlen1(char *str, t_pcub *cub)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	if (i > 2147483646 || i < 0)
	{
		print_free_exit(MAP_TOO_BIG, cub);
	}
	return (i);
}

static void	print_map_struct(t_map *map)
{
	printf("\n\n =======TEXTURE========\n\n");
	printf("%s\n", map->no);
	printf("%s\n", map->so);
	printf("%s\n", map->we);
	printf("%s", map->ea);
	printf("\n\n =======COLOR========\n\n");
	printf("%d\n", map->floor);
	printf("%d", map->ceiling);
	printf("\n\n =======MAP========\n\n");
	for (int i = 0; i < map->height; i++)
	{
		printf("%s\n", map->map[i]);
	}
}

int	main(int argc, char **argv)
{
	t_pcub	*cub;
	t_map	*map;

	cub = init_cub();
	parse_map(cub, argc, argv);
	map = init_map(cub);
	put_cub_in_map(&cub, map);
	print_map_struct(map);
	free_map(&map);
	return (0);
}
