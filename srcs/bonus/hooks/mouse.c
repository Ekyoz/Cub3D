/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:02:15 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:02:15 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_clamp_d(int value, int min, int max);

int	mouse_hook(int button, int x, int y, t_mouse *mouse)
{
	mouse->pressed = 1;
	mouse->pos.x = x;
	mouse->pos.y = y;
	mouse->button = button;
	return (0);
}

int	mouse_release(int button, int x, int y, t_mouse *mouse)
{
	(void)button;
	(void)x;
	(void)y;
	mouse->pressed = 0;
	return (0);
}

int	update_mouse_pos(int x, int y, t_mouse *mouse)
{
	mouse->move.x = WIDTH / 2 - x;
	if (mouse->move.y <= HEIGHT / 2 && mouse->move.y >= -HEIGHT / 2)
	{
		mouse->move.y += HEIGHT / 2 - y;
		mouse->move.y = ft_clamp_d(mouse->move.y, -HEIGHT / 2, HEIGHT / 2);
	}
	mouse->pos.x = x;
	mouse->pos.y = y;
	return (0);
}

static int	ft_clamp_d(int value, int min, int max)
{
	if (value < min)
		return (min);
	if (value > max)
		return (max);
	return (value);
}
