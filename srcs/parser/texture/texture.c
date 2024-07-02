/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:57:24 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/02 14:19:44 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// une fonction qui check la texture actuelle et qui verifie l'ordre a chaque fois
static void find_texture(char *str, int j, t_pcub *cub)
{
    // printf("dans la find texture str: %c\n", str[j]);
    if(str[j] == 'N' && str[j + 1] == 'O')
    {
        if(cub->northtext == false && cub->countorder == 0)
        {
            if(space_before(str, j))
                get_texture_face(cub, str, j, &(cub->notexture));
            cub->northtext = true;
            cub->countorder++;
        }
        else 
            print_free_exit(WRONG_ORDER, cub);
    }
    else if(str[j] == 'S' && str[j + 1] == 'O')
    {
        if(cub->southtext == false && cub->countorder == 1)
        {
            if(space_before(str, j))
                get_texture_face(cub, str, j, &(cub->sotexture));
            cub->southtext = true;
            cub->countorder++;
        }
        else 
            print_free_exit(WRONG_ORDER, cub);
    }
    else if(str[j] == 'W' && str[j + 1] == 'E')
    {
        if(cub->westtext == false && cub->countorder == 2)
        {
            if(space_before(str, j))
                get_texture_face(cub, str, j, &(cub->wetexture));
            cub->westtext = true;
            cub->countorder++;
        }
        else 
            print_free_exit(WRONG_ORDER, cub);
    }
    else if(str[j] == 'E' && str[j + 1] == 'A')
    {
        if(cub->easttext == false && cub->countorder == 3)
        {
            if(space_before(str, j))
                get_texture_face(cub, str, j, &(cub->eatexture));
            cub->easttext = true;
            cub->countorder++;
        }
        else 
            print_free_exit(WRONG_ORDER, cub);
    }
    else if(str[j] == 'F' && str[j + 1] == ' ')
    {
        if(cub->fcolor == false && cub->countorder == 4)
        {
            if(space_before(str,j))
                get_color_floor(cub, str, &(cub->color));
            cub->fcolor = true;
            cub->countorder++;
        }
        else 
            print_free_exit(WRONG_ORDER, cub);
    }
    else if(str[j] == 'C' && str[j + 1] == ' ')
    {
        if(cub->ccolor == false && cub->countorder == 5)
        {
            if(space_before(str,j))
                get_color_ceiling(cub, str, &(cub->color));
            cub->ccolor = true;
            cub->countorder++;
        }
        else 
        {
            print_free_exit(WRONG_ORDER, cub);
        }
    }
    // printf("%s et %s et %s et %s\n", cub->notexture, cub->sotexture, cub->wetexture, cub->eatexture);
    // printf("le ceiling %d et floor %d\n", cub->color->r_ceiling, cub->color->r_floor);
    // printf("le ceiling %d et floor %d\n", cub->color->g_ceiling, cub->color->g_floor);
    // printf("le ceiling %d et floor %d\n\n", cub->color->b_ceiling, cub->color->b_floor);
}

// la je cherche ma texture dans ma ligne 
static int search_texture(char *str, t_pcub *cub, int j)
{
    if(check_cmp(&str[j]))
    {
        find_texture(str, j, cub);
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
    while(i <= cub->linetexture)
    {
        j = 0;
        while(str[j] && ft_isspace(str[j]))
            j++;
        if(str[j] == '\0')
        {
            i++;
            if(i == cub->linetexture)
            {
                free(str);
                break;
            }
            free(str);
            str = get_next_line(cub->filefd);
            continue;
        }
        else
            search_texture(str, cub, j);
        free(str);
        str = get_next_line(cub->filefd);
        i++;
    }
    if(cub->countorder != 6)
        print_free_exit(WRONG_ORDER, cub);
}

static void countline_texture(t_pcub *cub)
{
    char *str;

    str = get_next_line(cub->filefd);
    if(str == NULL)
        print_free_exit(EMPTY_FILE, cub);
    // cub->texture = init_texture(cub);
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
    if(cub->linetexture == 0)
        print_free_exit(EMPTY_FILE, cub);
    printf("linetexture = %d\n", cub->linetexture);
}

void get_texture(t_pcub *cub, char *argv1)
{
    check_arg_extension(argv1, cub);
    cub->filefd = open_file(argv1, cub);
    countline_texture(cub);
    close(cub->filefd);
    cub->filefd = open_file(argv1, cub);
    put_texture(cub);
    // check_texture_extension(cub, cub->notexture);
    // check_texture_extension(cub, cub->sotexture);
    // check_texture_extension(cub, cub->eatexture);
    // check_texture_extension(cub, cub->wetexture);
}
