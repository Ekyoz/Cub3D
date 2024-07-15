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
				int tex_x);
static void	render_pix(t_cub *cub, t_vector_d points[2], int color_y[2],
				float slice_height);

void	rays_render(t_cub *cub)
{
	const int	slice_width = WIDTH / cub->rays_nb;
	int			i;

	i = 0;
	while (i < cub->rays_nb)
	{
		ray_render_loop(cub, slice_width, i);
		i++;
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
	points[0] = create_d_vect(i * slice_width, (HEIGHT / 2) - (int)slice_height
			/ 2);
	points[1] = create_d_vect(i * slice_width + slice_width, (HEIGHT / 2)
			+ (int)slice_height / 2);
	render_slice(cub, ray, points);
}

static void	render_slice(t_cub *cub, t_ray *ray, t_vector_d points[2])
{
	int			tex_x;
	t_sprite	*sprite;

	sprite = &cub->map.textures.walls[ray->side_hit];
	tex_x = get_tex_x(cub, ray, sprite);
	render_slice_loop(cub, points, ray, tex_x);
}

static void	render_slice_loop(t_cub *cub, t_vector_d points[2], t_ray *ray,
		int t_x)
{
	float		s_h;
	double		t_y;
	double		step;
	int			y;
	t_sprite	*sprite;

	t_y = 0;
	sprite = &cub->map.textures.walls[ray->side_hit];
	s_h = (float)(HEIGHT / ray->perp_length);
	step = sprite->height / s_h;
	y = points[0].y;
	while (++y < points[1].y)
	{
		if (y < 0)
		{
			t_y += -y * step;
			y = 0;
		}
		if (y >= HEIGHT)
			break ;
		if (y >= 0 && y < HEIGHT)
			render_pix(cub, points, (int [2]){get_text_pixel(sprite, t_x, t_y),
				y}, s_h);
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
