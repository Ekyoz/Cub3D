/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:51:35 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/08 12:51:35 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int get_tex_x(t_cub *cub, t_ray *ray, t_texture *texture)
{
	// Calculating exact hit position
	double perp_angle = PI_2 - ray->angle + get_angle_f(cub->player.pos, vector_d_to_f(cub->player.view_dst_pos));
	double  hit_length = ray->perp_length * 0.5f * TILE_SIZE / sin(perp_angle);
	t_vector_f wall_x = create_vect_f_from_origin(cub->player.pos, ray->angle, hit_length);

	float cell_pos;
	// Getting hit position relative to the cell
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

int get_text_pixel(t_texture *texture, int x, int y)
{
	int color;

	// Check out of texture coordinates
	if (x < 0 || x >= texture->width)
		return (0); // Returning black color
	if (y < 0 || y >= texture->height)
		return (0);

	color = (*(int *)texture->addr + (y * texture->line_length) + (x * texture->bits_per_pixel / 8));
	return (color);
}

t_texture load_texture(t_cub *cub, char *path)
{
	t_texture *texture;
	t_texture result;

	texture = (t_texture *) malloc(sizeof(t_texture));
	if (!texture)
		exit(1);
	texture->texture = mlx_xpm_file_to_image(cub->mlx.mlx, path, &texture->width, &texture->height);
	if (!texture->texture)
		exit(1);
	texture->addr = mlx_get_data_addr(texture->texture, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (texture->addr != NULL)
		printf("text: %p\n", texture->addr);
	result = *texture;
	free(texture);
	return result;
}