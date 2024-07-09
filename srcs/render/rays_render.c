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
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	rays_render(t_cub *cub)
{
	const int 	slice_width = WIDTH / cub->rays_nb;
	float 		slice_height;
	float 		color_timestamp;
	int			color;
	int 		tex_x;
	double 		tex_y;
	double 		step;
	t_vector_d 	top_left;
	t_vector_d 	bot_right;
	t_sprite 	*sprite;

	for (int i = 0; i < cub->rays_nb; ++i) {
		t_ray *ray = &cub->rays[i];
		
		if (ray->perp_length == -1)
			continue;

		ray->perp_length *= VIEW_DIST * 0.00125;

		slice_height = (float)(HEIGHT / ray->perp_length);

		top_left = create_d_vect(i * slice_width, (HEIGHT / 2 + cub->mouse.move.y) - (int)slice_height / 2);
		bot_right = create_d_vect(i * slice_width + slice_width,( HEIGHT / 2 + cub->mouse.move.y) + (int)slice_height / 2);
		color_timestamp = (slice_height - 10.0f) / (100.0f - 10.0f);

		if (cub->map.map[ray->cell.y][ray->cell.x] == '2' || cub->map.map[ray->cell.y][ray->cell.x] == '4')
			sprite = &cub->map.textures.door;
		else
			sprite = &cub->map.textures.walls[ray->side_hit];
		tex_x = get_tex_x(cub, ray, sprite);
		tex_y = 0;
		step = sprite->height / slice_height;

		for (int y = top_left.y; y < bot_right.y; y++) {
			if (y < 0)
			{
				tex_y += -y * step;
				y = 0;
			}
			if (y >= HEIGHT)
				break;
			if (y >= 0 && y < HEIGHT)
			{
				color = get_text_pixel(sprite, tex_x, tex_y);
				if (color_timestamp <= 0.98f)
					color = color_lerp(BLACK, color, color_timestamp);
				for (int x = top_left.x; x < bot_right.x; x++)
					my_mlx_pixel_put(&cub->mlx, x, y, color);
			}
			tex_y += step;
		}
	}
}