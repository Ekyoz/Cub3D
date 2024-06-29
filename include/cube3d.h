/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atresall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:24:11 by alexandre         #+#    #+#             */
/*   Updated: 2024/06/25 15:24:11 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
#define CUBE3D_H

#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include "parser.h"
#include "ray.h"
#include "structs.h"
#include "libft.h"
#include "errormessage.h"
#include "get_next_line.h"

typedef struct s_pcub
{
    char **texture;
    char **map;
    int filefd;
    int heighttext;
    int countorder;
    int linetexture;
    bool northtext;
    bool southtext;
    bool easttext;
    bool westtext;
    bool fcolor;
    bool ccolor;
} t_pcub;

typedef struct s_color
{
    unsigned int r_ceiling;
    unsigned int g_ceiling;
    unsigned int b_ceiling;
    unsigned int r_floor;
    unsigned int g_floor;
    unsigned int b_floor;
} t_color;



//PARSING
t_pcub      *init_cub();
int         open_file(char *argv1, t_pcub *cub);
void        parse_map(t_pcub *cub, int argc, char **argv);

//TEXTURE
void        get_texture(t_pcub *cub, char *argv1);
void check_texture_extension(char *argv1, t_pcub *cub);
char **init_texture(t_pcub *cub);
void texture_in_line(char *str);
int	check_cmp(char *line);

//UTILS
bool         is_map(char *str);
bool space_before(char *str, int index);

//FREE
void    free_cub(t_pcub **cub);
void    print_free_exit(char *str, t_pcub *cub);

#endif