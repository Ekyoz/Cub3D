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

#include "cub3d.h"

static void	ray_render_loop(t_cub *cub, int slice_width, int i);
static void	render_slice(t_cub *cub, t_ray *ray, t_vector_d points[2]);
static void	render_slice_loop(t_cub *cub, t_vector_d points[2], t_ray *ray,
				t_sprite *sprite);
static void	render_pix(t_cub *cub, t_vector_d points[2], int color_y[2],
				float slice_height);

void	rays_render(t_cub *cub)
{
	const int	slice_width = WIDTH / cub->rays_nb;
	int			i;

	i = -1;
	while (++i < cub->rays_nb)
	{
		ray_render_loop(cub, slice_width, i);
	}
}

static void	ray_render_loop(t_cub *cub, int slice_width, int i)
{
	float		slice_height;
	t_vector_d	points[2];
	t_ray		*ray;

	ray = &cub->rays[i];
	if (ray->perp_length == -1)
		return ;
	ray->perp_length *= VIEW_DIST * 0.00125;
	slice_height = (float)(HEIGHT / ray->perp_length);
	points[0] = create_d_vect(i * slice_width, (HEIGHT / 2 + cub->mouse.move.y)
			- (int)slice_height / 2);
	points[1] = create_d_vect(i * slice_width + slice_width, (HEIGHT / 2
				+ cub->mouse.move.y) + (int)slice_height / 2);
	render_slice(cub, ray, points);
}

static void	render_slice(t_cub *cub, t_ray *ray, t_vector_d points[2])
{
	t_sprite	*sprite;

	if (cub->map.map[ray->cell.y][ray->cell.x] == '2'
		|| cub->map.map[ray->cell.y][ray->cell.x] == '4')
		sprite = &cub->map.textures.door;
	else
		sprite = &cub->map.textures.walls[ray->side_hit];
	render_slice_loop(cub, points, ray, sprite);
}

static void	render_slice_loop(t_cub *cub, t_vector_d points[2], t_ray *ray,
		t_sprite *sprite)
{
	float	s_h;
	double	t_y;
	double	step;
	int		y_t_x[2];

	t_y = 0;
	s_h = (float)(HEIGHT / ray->perp_length);
	step = sprite->height / s_h;
	y_t_x[0] = points[0].y;
	y_t_x[1] = get_tex_x(cub, ray, sprite);
	while (++y_t_x[0] < points[1].y)
	{
		if (y_t_x[0] < 0)
		{
			t_y += -y_t_x[0] * step;
			y_t_x[0] = 0;
		}
		if (y_t_x[0] >= HEIGHT)
			break ;
		if (y_t_x[0] >= 0 && y_t_x[0] < HEIGHT)
			render_pix(cub, points, (int [2]){get_text_pixel(sprite, y_t_x[1],
					t_y), y_t_x[0]}, s_h);
		t_y += step;
	}
}

static void	render_pix(t_cub *cub, t_vector_d points[2], int color_y[2],
		float slice_height)
{
	int	x;

	x = points[0].x;
	if ((slice_height - 10.0f) / (100.0f - 10.0f) <= 0.98f)
		while (x++ < points[1].x)
			my_mlx_pixel_put(&cub->mlx, x, color_y[1], color_lerp(BLACK,
					color_y[0], (slice_height - 10.0f) / (100.0f - 10.0f)));
	else
		while (x++ < points[1].x)
			my_mlx_pixel_put(&cub->mlx, x, color_y[1], color_y[0]);
}
