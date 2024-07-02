/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:02:07 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/02 15:56:59 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// static void check_line_map(char *str, t_pcub *cub)
// {
//     int i;

//     i = 0;
//     while(str[i])
//     {
        
//     }
// }

void fill_map(t_pcub *cub)
{
    char *line;
    int i;

    i = 0;
    cub->map = (char **)malloc(sizeof(char *) * (cub->linemap + 1));
    if(!cub->map)
        print_free_exit(ERROR_MALLOC_INIT, cub);
    while(i < cub->linetexture)
    {
        get_next_line(cub->filefd);
        i++;
    }
    i = 0;
    while(i < cub->linemap)
    {
        line = get_next_line(cub->filefd);
        // printf("%s\n%d\n", line, i);
        if(line)
        {
            cub->map[i] = ft_strdup(line);
            // printf("%s", cub->map[i]);
        }
        free(line);
        line = NULL;
        i++;
    }
    // printf("\ni vaut %d\n", i);
    cub->map[i] = NULL;
}

void get_height_map(t_pcub *cub)
{
    char *line;

    line = get_next_line(cub->filefd);
    printf("======MAP======\n");
    while(line)
    {
        cub->linemap++;
        free(line);
        line = get_next_line(cub->filefd);
    }
    if(cub->linemap == 0)
        print_free_exit(NO_MAP, cub);
}
