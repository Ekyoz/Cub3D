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

#include "cube3d.h"

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
