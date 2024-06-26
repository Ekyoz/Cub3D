/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:21:21 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/26 14:37:31 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_pcub *init_cub()
{
    t_pcub *cub;

    cub = malloc(sizeof(t_pcub));
    if(!cub)
    {
        perror(ERROR_MALLOC_INIT);
        free_cub(&cub);
        exit(1);
    }
    cub->texture = NULL;
    cub->map = NULL;
    cub->filefd = -1;
    return cub;
}


void parse_map(t_pcub *cub, int argc, char **argv)
{
    if(argc != 2)
    {
        printf(ERROR_ARG);
        exit(1);
    }
    cub->filefd = open_file(argv[1], cub);
    get_texture(cub, argv[1]);
}