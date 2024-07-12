/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:53:48 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/02 14:53:48 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_r(int color)
{
	return ((color >> 16) & 0xFF);
}

int	ft_get_g(int color)
{
	return ((color >> 8) & 0xFF);
}

int	ft_get_b(int color)
{
	return (color & 0xFF);
}

int	ft_get_t(int color)
{
	return ((color >> 24) & 0xFF);
}

int	create_rgbt(int r, int g, int b, int t)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
