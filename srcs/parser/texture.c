/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:57:24 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/26 15:09:12 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void check_texture_ext(char *argv1, t_pcub *cub)
{
    char *str;
    // je check si l'extension est bien .cub
    str = ft_strnstr(argv1, ".cub", ft_strlen(argv1));
    // si l'extension n'est pas .cub ete si il y a plus de 4 caracteres apres le .
    if( str == NULL || ft_strlen(str) != 4) 
    {
        print_free_exit(ERROR_TEXTURE_EXT, cub);
    }
}

static void read_texture(t_pcub *cub)
{
    char *str;

    str = get_next_line(cub->filefd);
    if(str == NULL)
        print_free_exit(EMPTY_FILE, cub);
    while(str != NULL)
    {
        printf("%s\n", str);
        free(str);
        str = get_next_line(cub->filefd);
    }
    free(str);
}

void get_texture(t_pcub *cub, char *argv1)
{
    //check si bonne extension
    check_texture_ext(argv1, cub);
    cub->filefd = open_file(argv1, cub);
    read_texture(cub);
}
