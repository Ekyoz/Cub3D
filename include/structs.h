#ifndef CUBE3D_STRUCTS_H
#define CUBE3D_STRUCTS_H

#include "define.h"

// STRUCTS UTILS

typedef struct s_vector_d
{
	int x;
	int y;
} t_vector_d;

typedef struct s_vector_f
{
	float x;
	float y;
} t_vector_f;

// RAYCASTING STRUCTS

typedef struct s_mlx {
	void 		*mlx;
	void 		*win;
	void 		*img;
	char 		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
} t_mlx;

typedef struct s_texture{
	void *texture;
	char *addr;
	int width;
	int height;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_texture;

typedef struct s_map{
	char **map;
	int width;
	int height;

	char *NO;
	char *SO;
	char *WE;
	char *EA;
	t_texture walls[4];
	int floor;
	int ceiling;
} t_map;

typedef struct s_player
{
	t_vector_f pos;
	t_vector_f dir;
	t_vector_d view_dst_pos;
	int		map;
} t_player;

typedef struct s_ray {
	t_vector_f	hit_point;
	t_vector_d 	cell;
	t_vector_f	ray_dir;
	double		length;
	double		perp_length;
	double		angle;
	int			side_hit;
} t_ray;

typedef struct s_mouse {
	t_vector_d 	pos;
	t_vector_d 	move;
	int			pressed;
	int			button;
} t_mouse;

typedef struct s_keyboard
{
	int keyboard[200];
	int prev_keyboard[200];
} t_keyboard;

typedef struct s_cub {
	t_mlx mlx;
	t_map map;
	t_player player;
	t_ray *rays;
	t_mouse mouse;
	t_keyboard keyboard;

	int rays_nb;
} t_cub;

#endif //CUBE3D_STRUCTS_H
