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
# define CUBE3D_H

# include "errormessage.h"
# include "get_next_line.h"
# include "libft.h"
# include "parser.h"
# include "ray.h"
# include "structs.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;

	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor;
	int				ceiling;
}					t_map;

typedef struct s_color
{
	unsigned int	r_ceiling;
	unsigned int	g_ceiling;
	unsigned int	b_ceiling;
	unsigned int	r_floor;
	unsigned int	g_floor;
	unsigned int	b_floor;
	int				floor;
	int				ceiling;
}					t_color;

typedef struct s_pcub
{
	t_color			*color;
	char			*notexture;
	char			*sotexture;
	char			*wetexture;
	char			*eatexture;
	char			**map;
	int				x_max_size;
	int				y_max_size;
	int				filefd;
	int				counttexture;
	int				linetexture;
	int				linemap;
}					t_pcub;

// UTILS PARING
int					open_file(char *argv1, t_pcub *cub);

//PARSING
void        parse_map(t_pcub *cub, int argc, char **argv);

//STRUCT MANAGE
void        put_cub_in_map(t_pcub **cub, t_map *map);
t_map       *init_map(t_pcub *cub);
t_pcub      *init_cub();

//TEXTURE
void        get_texture(t_pcub *cub, char *argv1);
void        check_arg_extension(char *argv1, t_pcub *cub);
char        *check_texture_extension(t_pcub *cub, char *texture);
char        **init_texture(t_pcub *cub);
void        texture_in_line(char *str);
int	        check_cmp(char *line);

//FACE TEXTURE
void get_texture_face(t_pcub *cub, char *str, int j, char **face);

//COLORS
void        get_color_ceiling(t_pcub *cub, char *str, t_color **color);
void        get_color_floor(t_pcub *cub, char *str, t_color **color);
void        is_valid_color(char *str, t_pcub *cub);
int         check_space_inside(t_pcub *cub, char *str, char **split_color, char *line);
void        color_hex_floor(t_pcub *cub);
void        color_hex_ceiling(t_pcub *cub);
int        ft_tablen(char **tab);

//MAPS
void        get_height_map(t_pcub *cub);
void        fill_map(t_pcub *cub);
void        check_carac_map(t_pcub *cub);
void        check_lines(t_pcub *cub);
void        check_player_number(t_pcub *cub);
void        get_xy_maxsize(t_pcub *cub);
void        complete_map(t_pcub *cub);
void        check_closing_map(t_pcub *cub);

//UTILS
bool        is_map(char *str);
bool        space_before(char *str, int index);
bool        space_inside(char *start, char *end);
int         ft_strlen1(char *str, t_pcub *cub);

//FREE
void        print_free_exit(char *str, t_pcub *cub);
void	    free_array(char ***ptr);
void        free_cub(t_pcub **cub);
void        free_color(t_color **color);
void        free_map(t_map **map);

#endif