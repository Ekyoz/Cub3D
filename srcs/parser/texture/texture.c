/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:57:24 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/29 10:13:05 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// une fonction qui check la texture actuelle et qui verifie l'ordre a chaque fois
static void find_texture(char *str, int x, t_pcub *cub)
{
    printf("str de x = %c et %c\n", str[x], str[x + 1]);
    if(str[x] == 'N' && str[x + 1] == 'O')
    {
        printf("northtext = %d et countorder = %d\n", cub->northtext, cub->countorder);
        if(cub->northtext == false && cub->countorder == 0)
        {
            cub->northtext = true;
            cub->countorder++;
        }
    }
    else if(str[x] == 'S' && str[x + 1] == 'O')
    {
        if(cub->southtext == false && cub->countorder == 1)
        {
            cub->southtext = true;
            cub->countorder++;
        }
    }
    else if(str[x] == 'W' && str[x + 1] == 'E')
    {
        if(cub->westtext == false && cub->countorder == 2)
        {
            cub->westtext = true;
            cub->countorder++;
        }
    }
    else if(str[x] == 'E' && str[x + 1] == 'A')
    {
        if(cub->easttext == false && cub->countorder == 3)
        {
            cub->easttext = true;
            cub->countorder++;
        }
    }
    else if(str[x] == 'F')
    {
        if(cub->fcolor == false && cub->countorder == 4)
        {
            cub->fcolor = true;
            cub->countorder++;
        }
    }
    else if(str[x] == 'C')
    {
        if(cub->ccolor == false && cub->countorder == 5)
        {
            cub->ccolor = true;
            cub->countorder++;
        }
    }
}

// la je cherche ma texture dans ma ligne 
static int search_texture(char *str, t_pcub *cub)
{
    int x;

    x = 0;
    // je check si j'ai une texture
    if(check_cmp(str))
    {
        find_texture(str, x, cub);
    }
    return (0);
}

// je reitere dans mon fichier pour trouver mes textures
static void put_texture(t_pcub *cub)
{
    char *str;
    int i;
    int j;

    i = 0;
    str = get_next_line(cub->filefd);
    printf("str = %s\n", str);
    while(i < cub->linetexture)
    {
        j = 0;
        while(str[j] && ft_isspace(*str))
            j++;
        if(str[j] == '\0')
        {
            i++;
            if(i == cub->linetexture)
            {
                free(str);
                break;
            }
        }
        else
            search_texture(str, cub);
        free(str);
        str = get_next_line(cub->filefd);
        i++;
    }
    printf("countorder = %d\n", cub->countorder);
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
    // check si linetexture != 0
}

void get_texture(t_pcub *cub, char *argv1)
{
    //check si bonne extension
    check_texture_extension(argv1, cub);
    //ouverture fichier
    cub->filefd = open_file(argv1, cub);
    // read_texture(cub);
    countline_texture(cub);
    close(cub->filefd);
    cub->filefd = open_file(argv1, cub);
    put_texture(cub);
}
