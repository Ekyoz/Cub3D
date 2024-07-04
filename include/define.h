#ifndef CUBE3D_DEFINE_H
#define CUBE3D_DEFINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
#include "mlx.h"

// WINDOWS SETTINGS

#define WIDTH 1440
#define HEIGHT 900

// MAP SETTINGS
#define TILE_SIZE 40

// VIEW SETTINGS
#define FOV 66
#define VIEW_DIST 800

// SPEED
#define MOVE_SPEED 3
#define ROT_SPEED_KEY 0.045f
#define ROT_SPEED_MOUSE 1000.0f

// MATHS
# define PI		3.14
# define PI_2	1.57
# define PI_3	1.047
# define PI_4	0.785
# define PI_6	0.523

// MLX Colors
# define WHITE 0x00FFFFFF
# define DARK_GRAY 0x00222222
# define BLACK 0x00000000
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define PURPLE 0x00FF00FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define PINK 0x00DD88BB
# define LIGHT_BLUE 0x00AAAAFF

// KEYS
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define MOUSE_WHELL 3
# define LMB 1
# define RMB 2
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_R 15
# define KEY_O 31
# define KEY_P 35
# define KEY_TAB 48
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_E 14
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_1 83
# define KEY_2 84
# define KEY_4 86
# define KEY_5 87
# define KEY_7 89
# define KEY_8 91
# define KEY_PLUS 69
# define KEY_MINUS 78

#endif //CUBE3D_DEFINE_H
