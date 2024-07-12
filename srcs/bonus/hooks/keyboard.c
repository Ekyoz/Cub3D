/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:50:46 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 15:50:46 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_cub *cub)
{
	keycode = keycode % 200;
	if (keycode < 200)
	{
		cub->keyboard.prev_keyboard[keycode] = cub->keyboard.keyboard[keycode];
		cub->keyboard.keyboard[keycode] = 1;
	}
	if (cub->keyboard.keyboard[KEY_ESC])
		close_cub(cub, NULL, 0);
	return (0);
}

int	key_release(int keycode, t_keyboard *keyboard)
{
	keycode = keycode % 200;
	if (keycode < 200)
	{
		keyboard->prev_keyboard[keycode] = keyboard->keyboard[keycode];
		keyboard->keyboard[keycode] = 0;
	}
	return (1);
}
