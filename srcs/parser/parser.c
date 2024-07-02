/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:21:21 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/02 15:49:54 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// static void print_array(char **array)
// {
//     int i;

//     i = 0;
//     if(array)
//     {
//         while(array[i])
//         {
//             printf("%s", array[i]);
//             i++;
//         }
//     }
// }

static t_color *init_color(t_pcub *cub)
{
    t_color *color;

    color = malloc(sizeof(t_color));
    if(!color)
    {
        print_free_exit(ERROR_MALLOC_INIT, cub);
    }
    color->r_ceiling = 0;
    color->g_ceiling = 0;
    color->b_ceiling = 0;
    color->r_floor = 0;
    color->g_floor = 0;
    color->b_floor = 0;
    return color;
}

t_pcub *init_cub()
{
    t_pcub *cub;

    cub = malloc(sizeof(t_pcub));
    if(!cub)
    {
        print_free_exit(ERROR_MALLOC_INIT, cub);
    }
    cub->color = init_color(cub);
    cub->countorder = 0;
    cub->linetexture = 0;
    cub->linemap = 0;
    cub->northtext = false;
    cub->southtext = false;
    cub->easttext = false;
    cub->westtext = false;
    cub->fcolor = false;
    cub->ccolor = false;
    cub->notexture = NULL;
    cub->sotexture = NULL;
    cub->eatexture = NULL;
    cub->wetexture = NULL;
    cub->map = NULL;
    cub->filefd = -1;
    return cub;
}


void parse_map(t_pcub *cub, int argc, char **argv)
{
    if(argc != 2)
    {
        print_free_exit(ERROR_ARG, cub);
    }
    cub->filefd = open_file(argv[1], cub);
    get_texture(cub, argv[1]);
    get_height_map(cub);
    close(cub->filefd);
    cub->filefd = open_file(argv[1], cub);
    fill_map(cub);
    // print_array(cub->map);
}