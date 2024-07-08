/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:13 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 19:00:13 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	sort_points(t_vector_d *points[3]);
static void	fill_top_triangle(t_cub *data, t_vector_d points[3], int color);
static void	fill_bottom_triangle(t_cub *data, t_vector_d points[3], int color);

void	draw_triangle_color(t_cub *data, t_vector_d points[3], int color)
{
	sort_points(&points);
	if (points[1].y == points[2].y)
		fill_top_triangle(data, points, color);
	else if (points[0].y == points[1].y)
		fill_bottom_triangle(data, points, color);
	else
	{
		t_vector_d p4 = {
				(int)(points[0].x + (float)(points[1].y - points[0].y) / (float)(points[2].y - points[0].y) * (points[2].x - points[0].x)),
				points[1].y
		};
		t_vector_d top_tri[3] = {points[0], points[1], p4};
		fill_top_triangle(data, top_tri, color);
		t_vector_d bot_tri[3] = {points[1], p4, points[2]};
		fill_bottom_triangle(data, bot_tri, color);
	}
}

/*
	p0 is the heighest point
	p2 is the lowest point
*/

int	ft_get_min_3_d(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

void	ft_swap_v2_d(t_vector_d *a, t_vector_d *b)
{
	t_vector_d	temp;

	set_vector_d(&temp, a->x, a->y);
	set_vector_d(a, b->x, b->y);
	set_vector_d(b, temp.x, temp.y);
}

static void	sort_points(t_vector_d *points[3])
{
	t_vector_d *p0 = (*points);
	t_vector_d *p1 = (*points + 1);
	t_vector_d *p2 = (*points + 2);

	// heighest point
	if (ft_get_min_3_d(p0->y, p1->y, p2->y) != p0->y)
	{
		if (p1->y < p2->y)
			ft_swap_v2_d(p0, p1);
		else
			ft_swap_v2_d(p0, p2);
	}
	if (p1->y > p2->y)
		ft_swap_v2_d(p1, p2);

	// dprintf(1, "0 : %d %d\n", (*points)->x, (*points)->y);
	// dprintf(1, "1 : %d %d\n", (*points+1)->x, (*points+1)->y);
	// dprintf(1, "2 : %d %d\n", (*points+2)->x, (*points+2)->y);
}

/*
p0 is the higher point
p1 & p2 are on the same height
*/
static void	fill_top_triangle(t_cub *data, t_vector_d p[3], int color)
{
	float	inv_slope_1 = (float)(p[1].x - p[0].x) / (p[1].y - p[0].y);
	float	inv_slope_2 = (float)(p[2].x - p[0].x) / (p[2].y - p[0].y);

	float	curr_x_1 = p[0].x;
	float	curr_x_2 = p[0].x;

	for (int y = p[0].y; y <= p[1].y; y++)
	{
		t_vector_d	start = {(int)curr_x_1, y};
		t_vector_d	end = {(int)curr_x_2, y};
		bresenham(data, start, end, color);
		curr_x_1 += inv_slope_1;
		curr_x_2 += inv_slope_2;
	}
}

/*
p0 & & p1 are on the same height
p2 is the lowest point
*/
static void fill_bottom_triangle(t_cub *data, t_vector_d p[3], int color)
{
	float	inv_slope_1 = (float)(p[2].x - p[0].x) / (p[2].y - p[0].y);
	float	inv_slope_2 = (float)(p[2].x - p[1].x) / (p[2].y - p[1].y);

	float	curr_x_1 = p[2].x;
	float	curr_x_2 = p[2].x;

	for (int y = p[2].y; y >= p[0].y; y--)
	{
		t_vector_d	start = {(int)curr_x_1, y};
		t_vector_d	end = {(int)curr_x_2, y};
		bresenham(data, start, end, color);
		curr_x_1 -= inv_slope_1;
		curr_x_2 -= inv_slope_2;
	}
}