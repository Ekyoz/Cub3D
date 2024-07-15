/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:02:43 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/04 17:02:43 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	plot_line_high(t_cub *cub, t_vector_d p1, t_vector_d p2, int color);
static void	plot_line_low(t_cub *cub, t_vector_d p1, t_vector_d p2, int color);
static void	init_bresenham_low(int *dy, int *yi);
static void	init_bresenham_high(int *dx, int *xi);

void	bresenham(t_cub *cub, t_vector_d p1, t_vector_d p2, int color)
{
	if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			plot_line_low(cub, p2, p1, color);
		else
			plot_line_low(cub, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			plot_line_high(cub, p2, p1, color);
		else
			plot_line_high(cub, p1, p2, color);
	}
}

static void	plot_line_high(t_cub *cub, t_vector_d p1, t_vector_d p2, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	init_bresenham_high(&dx, &xi);
	d = 2 * dx - dy;
	x = p1.x;
	while (p1.y <= p2.y)
	{
		my_mlx_pixel_put(&cub->mlx, x, p1.y, color);
		if (d > 0)
		{
			x += xi;
			d -= 2 * dy;
		}
		d += 2 * dx;
		p1.y++;
	}
}

static void	plot_line_low(t_cub *cub, t_vector_d p1, t_vector_d p2, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	init_bresenham_low(&dy, &yi);
	d = 2 * dy - dx;
	y = p1.y;
	while (p1.x <= p2.x)
	{
		my_mlx_pixel_put(&cub->mlx, p1.x, y, color);
		if (d > 0)
		{
			y += yi;
			d -= 2 * dx;
		}
		d += 2 * dy;
		p1.x++;
	}
}

static void	init_bresenham_low(int *dy, int *yi)
{
	*yi = 1;
	if (*dy < 0)
	{
		*yi = -1;
		*dy = -*dy;
	}
}

static void	init_bresenham_high(int *dx, int *xi)
{
	*xi = 1;
	if (*dx < 0)
	{
		*xi = -1;
		*dx = -*dx;
	}
}
