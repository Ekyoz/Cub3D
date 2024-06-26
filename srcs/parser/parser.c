/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:21:21 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/26 19:48:26 by bpoyet           ###   ########.fr       */
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
    cub->countorder = 0;
    cub->linetexture = 0;
    cub->texture = NULL;
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
}