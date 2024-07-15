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

#include "cub3d.h"

int	get_tex_x(t_cub *cub, t_ray *ray, t_sprite *texture)
{
	double		perp_angle;
	double		hit_length;
	t_vector_f	wall_x;
	float		cell_pos;
	int			tex_x;

	perp_angle = PI_2 - ray->angle + get_angle_f(cub->player.pos,
			vector_d_to_f(cub->player.view_dst_pos));
	hit_length = ray->perp_length * 0.5f * TILE_SIZE / sin(perp_angle);
	wall_x = create_vect_f_from_origin(cub->player.pos, ray->angle, hit_length);
	if (ray->side_hit == 1 || ray->side_hit == 3)
		cell_pos = wall_x.y - (int)(wall_x.y / TILE_SIZE) *TILE_SIZE;
	else
		cell_pos = wall_x.x - (int)(wall_x.x / TILE_SIZE) *TILE_SIZE;
	if (ray->side_hit == 3 || ray->side_hit == 2)
		cell_pos = cell_pos / TILE_SIZE;
	else
		cell_pos = 1.0f - cell_pos / TILE_SIZE;
	tex_x = cell_pos * texture->width;
	return (tex_x);
}

int	get_text_pixel(t_sprite *texture, int x, int y)
{
	int		color;
	char	*pixel;

	if (x < 0 || x >= texture->width)
		return (0);
	if (y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	color = *(int *)pixel;
	return (color);
}

t_sprite	load_texture(t_cub *cub, char *path)
{
	t_sprite	*texture;
	t_sprite	result;

	texture = (t_sprite *)malloc(sizeof(t_sprite));
	if (!texture)
		close_cub(cub, ERROR_MALLOC_INIT, 1);
	texture->texture = mlx_xpm_file_to_image(cub->mlx.mlx, path,
			&texture->width, &texture->height);
	if (!texture->texture)
		close_cub(cub, TEXTURE_PROBLEM, 1);
	texture->addr = mlx_get_data_addr(texture->texture,
			&texture->bits_per_pixel, &texture->line_length, &texture->endian);
	result = *texture;
	free(texture);
	return (result);
}
