/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_color_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:32:48 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/02 12:57:20 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void get_texture_face(t_pcub *cub, char *str, int j, char **face)
{
    char *start;
    char *end;
    
    start = ft_strchr(str, '.');
    end = ft_strchr(str, '\n');
    if(start && end && space_inside(&str[j + 2], start))
    {
        *face = ft_substr(str, start - str, end - start);
        if(!(*face))
            print_free_exit(NO_NAME_TEXTURE, cub);
    }
    else
        print_free_exit(ERROR_FACE_TEXTURE, cub);
}

void get_color_ceiling(t_pcub *cub, char *str, t_color **color)
{
    char *start;
    char **split_color;
    int nb;

    nb = 0;
    start = ft_strchr(str, ' ');
    is_valid_color(start, cub);
    split_color = ft_split(start, ',');
    if(!split_color)
        print_free_exit(COMB_COLOR, cub);
    while(split_color[nb])
        nb += check_space_inside(cub, split_color[nb]);
    if(ft_tablen(split_color) == 3 && nb == 3)
    {
        (*color)->r_ceiling = ft_atoi(split_color[0]);
        (*color)->g_ceiling = ft_atoi(split_color[1]);
        (*color)->b_ceiling = ft_atoi(split_color[2]);
    }
    else
        print_free_exit(TREE_COLOR, cub);
    color_hex_ceiling(cub);
    free_array(&split_color);
    if(cub->color->r_ceiling > 255 || cub->color->g_ceiling > 255 ||
        cub->color->b_ceiling > 255)
        print_free_exit(COLOR_NUMBER, cub);
}

void get_color_floor(t_pcub *cub, char *str, t_color **color)
{
    char *start;
    char **split_color;
    int nb;

    nb = 0;
    start = ft_strchr(str, ' ');
    is_valid_color(start, cub);
    split_color = ft_split(start, ',');
    if(!split_color)
        print_free_exit(COMB_COLOR, cub);
    while(split_color[nb])
        nb += check_space_inside(cub, split_color[nb]);
    if(ft_tablen(split_color) == 3 && nb == 3)
    {
        (*color)->r_floor = ft_atoi(split_color[0]);
        (*color)->g_floor = ft_atoi(split_color[1]);
        (*color)->b_floor = ft_atoi(split_color[2]);
    }
    else
        print_free_exit(TREE_COLOR, cub);
    color_hex_floor(cub);
    free_array(&split_color);
    if(cub->color->r_floor > 255 || cub->color->g_floor > 255 ||
        cub->color->b_floor > 255)
        print_free_exit(COLOR_NUMBER, cub);
}

