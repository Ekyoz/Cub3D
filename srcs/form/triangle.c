/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:13 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/09 17:40:42 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	fill_top_triangle(t_cub *data, t_vector_d points[3], int color);
static void	fill_bottom_triangle(t_cub *data, t_vector_d points[3], int color);

void	draw_triangle_color(t_cub *data, t_vector_d points[3], int color)
{
	t_vector_d	p4;
	t_vector_d	top_tri[3];
	t_vector_d	bot_tri[3];

	sort_points(&points);
	if (points[1].y == points[2].y)
		fill_top_triangle(data, points, color);
	else if (points[0].y == points[1].y)
		fill_bottom_triangle(data, points, color);
	else
	{
		set_vector_d(&p4, (int)(points[0].x + (float)(points[1].y - points[0].y)
				/ (float)(points[2].y - points[0].y) *(points[2].x
					- points[0].x)), points[1].y);
		top_tri[0] = points[0];
		top_tri[1] = points[1];
		top_tri[2] = p4;
		fill_top_triangle(data, top_tri, color);
		bot_tri[0] = points[1];
		bot_tri[1] = p4;
		bot_tri[2] = points[2];
		fill_bottom_triangle(data, bot_tri, color);
	}
}

static void	fill_top_triangle(t_cub *data, t_vector_d p[3], int color)
{
	float	inv_slope_1;
	float	inv_slope_2;
	float	curr_x_1;
	float	curr_x_2;
	int		y;

	inv_slope_1 = (float)(p[1].x - p[0].x) / (p[1].y - p[0].y);
	inv_slope_2 = (float)(p[2].x - p[0].x) / (p[2].y - p[0].y);
	curr_x_1 = p[0].x;
	curr_x_2 = p[0].x;
	y = p[0].y;
	while (y <= p[1].y)
	{
		bresenham(data, create_d_vect((int)curr_x_1, y),
			create_d_vect((int)curr_x_2, y), color);
		curr_x_1 += inv_slope_1;
		curr_x_2 += inv_slope_2;
		y++;
	}
}

static void	fill_bottom_triangle(t_cub *data, t_vector_d p[3], int color)
{
	float	inv_slope_1;
	float	inv_slope_2;
	float	curr_x_1;
	float	curr_x_2;
	int		y;

	inv_slope_1 = (float)(p[2].x - p[0].x) / (p[2].y - p[0].y);
	inv_slope_2 = (float)(p[2].x - p[1].x) / (p[2].y - p[1].y);
	curr_x_1 = p[2].x;
	curr_x_2 = p[2].x;
	y = p[2].y;
	while (y >= p[0].y)
	{
		bresenham(data, create_d_vect((int)curr_x_1, y),
			create_d_vect((int)curr_x_2, y), color);
		curr_x_1 -= inv_slope_1;
		curr_x_2 -= inv_slope_2;
		y--;
	}
}
