/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:52:37 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/03 19:59:00 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char *dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_tex_x(t_cub *cub, t_ray *ray, t_texture *texture)
{
	// Calculating exact hit position
	double perp_angle = PI_2 - ray->angle + get_angle_f(cub->player.pos, vector_d_to_f(cub->player.view_dst_pos));
	double	hit_length = ray->perp_length * 0.5f * TILE_SIZE / sin(perp_angle);
	t_vector_f wall_x = create_vect_f_from_origin(cub->player.pos, ray->angle, hit_length);

	float cell_pos;
	if (ray->side_hit == 1 || ray->side_hit == 3) // Horizontal hit
		cell_pos = wall_x.y - (int)(wall_x.y / TILE_SIZE) * TILE_SIZE;
	else // Vertical hit
		cell_pos = wall_x.x - (int)(wall_x.x / TILE_SIZE) * TILE_SIZE;

	if (ray->side_hit == 3 || ray->side_hit == 2) // Converting cell_pos to ratio
		cell_pos = cell_pos / TILE_SIZE;
	else // Flip texture if the side hit is the top or the right side of a cell
		cell_pos = 1.0f - cell_pos / TILE_SIZE;

	int tex_x = cell_pos * texture->width; // Mapping ratio to texture dimension

	return (tex_x);
}

void	rays_render(t_cub *cub)
{
	const int slice_width = WIDTH / cub->rays_nb;

	for (int i_ray = 0; i_ray < cub->rays_nb; ++i_ray) {
		t_ray *ray = &cub->rays[i_ray];
		if (ray->perp_length == -1)
			continue;

		ray->perp_length *= VIEW_DIST * 0.00125;

		float slice_height = (float)(HEIGHT / ray->perp_length);

		// Calculating top left corner position of the slice to draw
		t_vector_d tl = {
				i_ray * slice_width, // X
				(HEIGHT / 2 + cub->mouse.move.y) + slice_height / 2 // Y
		};

// Same for bottom right corner
		t_vector_d br = {
				i_ray * slice_width + slice_width, // X
				(HEIGHT / 2 + cub->mouse.move.y) - slice_height / 2 // Y
		};

		t_texture *texture;
		texture = &cub->map.walls[ray->side_hit]; // Wall texture

		double tex_y = 0;
		int	tex_x = get_tex_x(cub, ray, texture);
		double step = texture->height / slice_height;

		float color_timestamp = (slice_height - 10.0f) / (100.0f - 10.0f);

		for (int y = tl.y; y > br.y; --y) {

//			if (y < 0)
//			{
//				tex_y += -y * step;
//				y = 0;
//			}
//
			if (y >= HEIGHT)
				break;

			if (y >= 0 && y < HEIGHT)
			{
				int color;

				if (ray->side_hit == 0)
					color = RED;
				else if (ray->side_hit == 1)
					color = GREEN;
				else if (ray->side_hit == 2)
					color = BLUE;
				else
					color = YELLOW;

//				if (color_timestamp <= 0.98f)
//					color = color_lerp(BLACK, color, color_timestamp);
				for (int x = tl.x; x < br.x; x++)
					my_mlx_pixel_put(&cub->mlx, x, y, color);
			}
//			tex_y += step;
		}
	}
}