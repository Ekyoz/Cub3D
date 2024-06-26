/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:57:24 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/26 19:52:14 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void check_texture_extension(char *argv1, t_pcub *cub)
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

static char **init_texture(t_pcub *cub)
{
    char **texture;
    int i;

    i = 0;
    texture = (char **)malloc(sizeof(char *) * 5);
    if(!texture)
        print_free_exit(ERROR_MALLOC_INIT, cub);
    while(i < 5)
    {
        texture[i] = NULL;
        i++;
    }
    return texture;
}

static void texture_in_line(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        while(str[i] && ft_isspace(str[i]))
            i++;
        i++;
    }
}

static void put_texture(t_pcub *cub)
{
    int i;

    i = 0;
    while(i < cub->linetexture)
    {
        
        i++;
    }

}

static void countline_texture(t_pcub *cub)
{
    char *str;

    str = get_next_line(cub->filefd);
    if(str == NULL)
        print_free_exit(EMPTY_FILE, cub);
    cub->texture = init_texture(cub);
    while(str != NULL && !is_map(str))
    {
        cub->linetexture++;
        free(str);
        str = get_next_line(cub->filefd);
    }
    while(str)
    {
        free(str);
        str = get_next_line(cub->filefd);
    }
    free(str);
    printf("linetexture = %d\n", cub->linetexture);
}

void get_texture(t_pcub *cub, char *argv1)
{
    //check si bonne extension
    check_texture_extension(argv1, cub);
    //ouverture fichier
    cub->filefd = open_file(argv1, cub);
    read_texture(cub);
    countline_texture(cub);
    close(cub->filefd);
    cub->filefd = open_file(argv1, cub);
    put_texture(cub);
}
