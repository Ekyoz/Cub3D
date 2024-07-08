/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:00:05 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 19:00:05 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void draw_rect_filled_color(t_cub *data, t_vector_d top_left, t_vector_d bottom_right, int color)
{
	for (int y = top_left.y; y < bottom_right.y; y++)
	{
		for (int x = top_left.x; x < bottom_right.x; x++)
		{
			my_mlx_pixel_put(&data->mlx, x, y, color);
		}
	}
}

void draw_rounded_rect_filled_color(t_cub *data, t_vector_d top_left, t_vector_d bottom_right, int radius, int color) {
	int x, y;
	double rad_sqr = (double)radius * radius;

	for (y = top_left.y; y < bottom_right.y; y++) {
		for (x = top_left.x; x < bottom_right.x; x++) {
			if ((x < top_left.x + radius && y < top_left.y + radius && pow(x - top_left.x - radius, 2) + pow(y - top_left.y - radius, 2) <= rad_sqr) ||
				(x >= bottom_right.x - radius && y < top_left.y + radius && pow(x - bottom_right.x + radius, 2) + pow(y - top_left.y - radius, 2) <= rad_sqr) ||
				(x < top_left.x + radius && y >= bottom_right.y - radius && pow(x - top_left.x - radius, 2) + pow(y - bottom_right.y + radius, 2) <= rad_sqr) ||
				(x >= bottom_right.x - radius && y >= bottom_right.y - radius && pow(x - bottom_right.x + radius, 2) + pow(y - bottom_right.y + radius, 2) <= rad_sqr)) {
				my_mlx_pixel_put(&data->mlx, x, y, color);
			} else if ((x >= top_left.x + radius && x < bottom_right.x - radius && y >= top_left.y && y < bottom_right.y) ||
					   (y >= top_left.y + radius && y < bottom_right.y - radius && x >= top_left.x && x < bottom_right.x)) {
				my_mlx_pixel_put(&data->mlx, x, y, color);
			}
		}
	}
}
void draw_rounded_rect_color(t_cub *data, t_vector_d top_left, t_vector_d bottom_right, int radius, int color) {
	int x, y;
	double rad_sqr = (double)radius * radius;

	// Dessin des bords horizontaux
	for (x = top_left.x+radius; x <= bottom_right.x-radius; x++) {
		// Bord supérieur
		for (int t = 0; t < radius; t++) {
			my_mlx_pixel_put(&data->mlx, x, top_left.y + t, color);
		}
		// Bord inférieur
		for (int t = 0; t < radius; t++) {
			my_mlx_pixel_put(&data->mlx, x, bottom_right.y - 1 - t, color);
		}
	}

	// Dessin des bords verticaux
	for (y = top_left.y+radius; y <= bottom_right.y-radius; y++) {
		// Bord gauche
		for (int t = 0; t < radius; t++) {
			my_mlx_pixel_put(&data->mlx, top_left.x + t, y, color);
		}
		// Bord droit
		for (int t = 0; t < radius; t++) {
			my_mlx_pixel_put(&data->mlx, bottom_right.x - 1 - t, y, color);
		}
	}

	// Dessin des coins arrondis
	for (y = top_left.y; y < top_left.y + radius; y++) {
		for (x = top_left.x; x < top_left.x + radius; x++) {
			if (pow(x - top_left.x - radius, 2) + pow(y - top_left.y - radius, 2) <= rad_sqr) {
				my_mlx_pixel_put(&data->mlx, x, y, color);  // Coin supérieur gauche
			}
		}
		for (x = bottom_right.x - radius; x < bottom_right.x; x++) {
			if (pow(x - bottom_right.x + radius, 2) + pow(y - top_left.y - radius, 2) <= rad_sqr) {
				my_mlx_pixel_put(&data->mlx, x, y, color);  // Coin supérieur droit
			}
		}
	}

	for (y = bottom_right.y - radius; y < bottom_right.y; y++) {
		for (x = top_left.x; x < top_left.x + radius; x++) {
			if (pow(x - top_left.x - radius, 2) + pow(y - bottom_right.y + radius, 2) <= rad_sqr) {
				my_mlx_pixel_put(&data->mlx, x, y, color);  // Coin inférieur gauche
			}
		}
		for (x = bottom_right.x - radius; x < bottom_right.x; x++) {
			if (pow(x - bottom_right.x + radius, 2) + pow(y - bottom_right.y + radius, 2) <= rad_sqr) {
				my_mlx_pixel_put(&data->mlx, x, y, color);  // Coin inférieur droit
			}
		}
	}
}