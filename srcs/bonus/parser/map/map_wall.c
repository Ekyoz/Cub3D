/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:17:39 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/03 23:31:22 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static bool check_near_case(t_pcub *cub, int i, int j)
{
    if(i < 0 || j < 0 )
        return (false);
    if(i >= cub->y_max_size || j >= cub->x_max_size)
        return (false);
    if(i >= 0 && j >= 0 && i < cub->y_max_size &&
         j < cub->x_max_size && (cub->map[i][j] == ' ' || 
         cub->map[i][j] == '\n' || cub->map[i][j] == '\0'))
         {
            return (false);
         }
    return(true);
}

bool check_floor(t_pcub *cub, int i, int j)
{
    if(!check_near_case(cub, i, j + 1) || !check_near_case(cub, i, j - 1) || 
        !check_near_case(cub, i + 1, j) || !check_near_case(cub, i - 1, j))
        return (false);
    return(true);
}

void check_closing_map(t_pcub *cub)
{
    int i;
    int j;

    i = 0;
    while(cub->map[i])
    {
        j = 0;
        while(cub->map[i][j])
        {
            if(cub->map[i][j] == '0' && !check_floor(cub, i, j))
            {
                print_free_exit(MAP_NOT_CLOSED, cub);
            }
            j++;
        }
        i++;
    }
}
