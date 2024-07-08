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

#include "structs.h"
#include "define.h"
#include "mlx.h"


// INIT
int init_mlx(t_mlx *mlx);
int init_rays(t_cub *cub);
int init_input(t_mouse *mouse, t_keyboard *keyboard, void *win);
int init_texture(t_cub *cub);

// LOOP
void loop(t_cub *cub);

// RAYCASTING
void create_rays(t_cub *cub);
t_vector_f dda(t_cub *cub, t_ray *ray);
void rays_collisions(t_cub *cub);
int is_in_map(t_cub *cub, t_vector_d pos);
int		is_colliding_cell(t_cub *cub, float x, float y);

//RENDER
void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void set_floor_cell(t_cub *cub);
void rays_render(t_cub *cub);
void	bresenham(t_cub *data, t_vector_d p1, t_vector_d p2, int color);
void draw_rect_filled_color(t_cub *cub, t_vector_d top_left, t_vector_d bottom_right, int color);
void	draw_circle_color_radius(t_cub *data, t_vector_d center, int color, int radius);
void	draw_circle_empty(t_cub *data, t_vector_d center, int radius, int thickness);
void	draw_triangle_color(t_cub *data, t_vector_d points[3], int color);
void draw_rounded_rect_filled_color(t_cub *data, t_vector_d top_left, t_vector_d bottom_right, int radius, int color);
void draw_rounded_rect_color(t_cub *data, t_vector_d top_left, t_vector_d bottom_right, int thickness, int color);
void render_map(t_cub *cub);

// TEXTURE
int	get_text_pixel(t_texture *text, int x, int y);
int get_tex_x(t_cub *cub, t_ray *ray, t_texture *texture);
t_texture load_texture(t_cub *cub, char *path);

// HOOKS
int key_press(int keycode, t_keyboard *keyboard);
int key_release(int keycode, t_keyboard *keyboard);
int mouse_hook(int button, int x, int y, t_mouse *mouse);
int mouse_release(int button, int x, int y, t_mouse *mouse);
int update_mouse_pos(int x, int y, t_mouse *mouse);

//MOVE
void move_forward(t_cub *cub);
void move_backward(t_cub *cub);
void move_left(t_cub *cub);
void move_right(t_cub *cub);
void rotate_right(t_player *player, float coef);
void rotate_left(t_player *player, float coef);
void player_input(t_cub *cub, t_keyboard *keyboard, t_mouse *mouse);

//COLORS
// Rgb
int	ft_get_r(int color);
int	ft_get_g(int color);
int	ft_get_b(int color);
int	ft_get_t(int color);
int	create_rgbt(int r, int g, int b, int t);
// lerp
int	color_lerp(int color1, int color2, float timestamp);

// MATHS
// Vector
t_vector_f	vector_d_to_f(t_vector_d vector_d);
t_vector_d	vector_f_to_d(t_vector_f vector_f);
float len_squared(t_vector_d start, t_vector_d end);
double	get_vector_f_length(t_vector_f start, t_vector_f end);
t_vector_f	create_vect_f_from_origin(t_vector_f origin, double radian, double length);
t_vector_d	create_vect_d_from_origin(t_vector_d origin, float radian, float length);
t_vector_d create_d_vect(int x, int y);
void	set_vector_d(t_vector_d *vector, int x, int y);
void	set_vector_f(t_vector_f *vector, float x, float y);
t_vector_d	vector_d_lerp(t_vector_d start, t_vector_d end, float timestamp);
t_vector_f	vector_f_lerp(t_vector_f start, t_vector_f end, float timestamp);
t_vector_d	rotate_vector_d(t_vector_d vector, double radian);
t_vector_f	rotate_vector_f(t_vector_f vector, double radian);
// DEG / RAD
double	radian_to_degree(double radian);
double	degree_to_radian(double degree);
double	get_angle(t_vector_d start, t_vector_d end);
double	get_angle_f(t_vector_f start, t_vector_f end);
// Direction
double get_direction(t_vector_d start, t_vector_d end);
double get_direction_f(t_vector_f start, t_vector_f end);
// Others
float ft_abs_f(float nb);

#include "libft.h"
#include "errormessage.h"
#include "get_next_line.h"

typedef struct s_map{
    char **map;
    int width;
    int height;

    char *NO;
    char *SO;
    char *WE;
    char *EA;
    int floor;
    int ceiling;
} t_map;

typedef struct s_color
{
    unsigned int r_ceiling;
    unsigned int g_ceiling;
    unsigned int b_ceiling;
    unsigned int r_floor;
    unsigned int g_floor;
    unsigned int b_floor;
    int floor;
    int ceiling;
} t_color;

typedef struct s_pcub
{
    t_color *color;
    char *notexture;
    char *sotexture;
    char *wetexture;
    char *eatexture;
    char **map;
    int x_max_size;
    int y_max_size;
    int filefd;
    int countorder;
    int linetexture;
    int linemap;
} t_pcub;

//UTILS PARING
int         open_file(char *argv1, t_pcub *cub);

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