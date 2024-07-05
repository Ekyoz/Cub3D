/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atresall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:24:11 by alexandre          #+#    #+#             */
/*   Updated: 2024/06/25 15:24:11 by alexandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int ft_strlen1(char *str, t_pcub *cub)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
    if(i > 2147483646 || i < 0)
    {
        print_free_exit(MAP_TOO_BIG, cub);
    }
	return (i);
}
static void print_map_struct(t_map *map)
{
    printf("\n\n =======TEXTURE========\n\n");
    printf("%s\n", map->NO);
    printf("%s\n", map->SO);
    printf("%s\n", map->WE);
    printf("%s\n", map->EA);
    printf("\n\n =======COLOR========\n\n");
    printf("%d\n", map->floor);
    printf("%d\n", map->ceiling);
    printf("\n\n =======MAP========\n\n");
    for(int i = 0; i < map->height; i++)
    {
        printf("%s\n", map->map[i]);
    }
}

int main(int argc, char **argv) {
    
    t_pcub *cub;
    t_map *map;
    cub = init_cub();
    map = init_map(cub);
    parse_map(cub, argc, argv);
    put_cub_in_map(&cub, map);
    print_map_struct(map);
    free_map(&map);
    return 0;
}
