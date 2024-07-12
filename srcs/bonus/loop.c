/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:45:56 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:02:04 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static int	update(t_cub *cub);

void	loop(t_cub *cub)
{
	mlx_hook(cub->mlx.win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx.win, 3, 1L << 1, key_release, &cub->keyboard);
	mlx_hook(cub->mlx.win, 4, 1L << 2, mouse_hook, &cub->mouse);
	mlx_hook(cub->mlx.win, 5, 1L << 3, mouse_release, &cub->mouse);
	mlx_hook(cub->mlx.win, 6, 1L << 6, update_mouse_pos, &cub->mouse);
	mlx_hook(cub->mlx.win, 17, 1L << 0, close_cub, cub);
	mlx_loop_hook(cub->mlx.mlx, update, cub);
	mlx_loop(cub->mlx.mlx);
}

static int	update(t_cub *cub)
{
	player_input(cub, &cub->keyboard, &cub->mouse);
	if (cub->player.map)
	{
		mlx_mouse_show(cub->mlx.win, cub->mlx.win);
		clear_window(cub);
		set_grid_cell(cub, cub->mouse.pos.x, cub->mouse.pos.y);
		print_grid(cub);
		bresenham(cub, vector_f_to_d(cub->player.pos), cub->player.view_dst_pos,
			GREEN);
		draw_circle_color_radius(cub, vector_f_to_d(cub->player.pos), RED, 5);
	}
	create_rays(cub);
	rays_collisions(cub);
	if (!cub->player.map)
	{
		set_floor_cell(cub);
		rays_render(cub);
	}
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	render_map(cub);
	return (0);
}
