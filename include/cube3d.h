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
int init_mouse(t_mouse *mouse, void *win);

// LOOP
void loop(t_cub *cub);

// RAYCASTING
void create_rays(t_cub *cub);
t_vector_f dda(t_cub *cub, t_ray *ray);
void rays_collisions(t_cub *cub);
int is_in_map(t_cub *cub, t_vector_d pos);

//RENDER
void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void set_floor_cell(t_cub *cub);
void rays_render(t_cub *cub);
void	bresenham(t_cub *data, t_vector_d p1, t_vector_d p2, int color);
void draw_rect_filled_color(t_cub *cub, t_vector_d top_left, t_vector_d bottom_right, int color);

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
int	is_colliding_cell(t_cub *cub, float x, float y);

//COLORS
// Rgb
int	ft_get_r(int color);
int	ft_get_g(int color);
int	ft_get_b(int color);
int	ft_get_t(int color);
int	create_rgbt(int r, int g, int b, int t);
// lerp
int	color_lerp(int color1, int color2, float timestamp);
int	get_text_pix(t_texture *text, int x, int y);

// MATHS
// Vector
t_vector_f	vector_d_to_f(t_vector_d vector_d);
t_vector_d	vector_f_to_d(t_vector_f vector_f);
float len_squared(t_vector_d start, t_vector_d end);
double	get_vector_f_length(t_vector_f start, t_vector_f end);
t_vector_f	create_vect_f_from_origin(t_vector_f origin, double radian, double length);
t_vector_d	create_vect_d_from_origin(t_vector_d origin, float radian, float length);
t_vector_d create_d_vect(int x, int y);
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


#endif
