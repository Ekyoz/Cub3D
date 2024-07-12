/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:32:34 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/03 23:33:58 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void get_maxsize_x(t_pcub *cub)
{
    int i;

    i = 0;
    while(cub->map[i])
    {
        if(ft_strlen1(cub->map[i], cub) > cub->x_max_size)
            cub->x_max_size = ft_strlen1(cub->map[i], cub);
        i++;
    }
}

static void get_maxsize_y(t_pcub *cub)
{
    int i;

    i = 0;
    while(cub->map[i])
    {
        i++;
    }
    cub->y_max_size = i;
}

void get_xy_maxsize(t_pcub *cub)
{
    get_maxsize_x(cub);
    get_maxsize_y(cub);
}