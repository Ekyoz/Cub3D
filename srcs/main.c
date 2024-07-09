/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
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


int main(int argc, char *argv[])
{
	t_pcub *p_cub;
	t_map *map;
	t_cub cub;
	p_cub = init_cub();
	parse_map(p_cub, argc, argv);
	map = init_map(p_cub);
	put_cub_in_map(&p_cub, map);

	cub.map = *map;
	cub.map.textures.DO = "./assets/door.xpm";

	if (init_mlx(&cub.mlx) == 1)
		exit(1);
	if (init_rays(&cub) == 1)
		exit(1);
	if (init_input(&cub.mouse, &cub.keyboard, cub.mlx.win) == 1)
		exit(1);
	if (initr_texture(&cub) == 1)
		exit(1);
	if (init_player(&cub) == 1)
		exit(1);

	loop(&cub);
	free_map(&map);
}