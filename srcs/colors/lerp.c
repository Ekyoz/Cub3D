/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lerp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:52:42 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/02 14:52:42 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"


int	ft_lerp_d(int min, int max, float timestamp)
{
	return ((max - min) * timestamp + min);
}

int	color_lerp(int color1, int color2, float timestamp)
{
	int	r;
	int	g;
	int	b;

	if (timestamp > 1.0f)
		timestamp = 1.0f;
	r = ft_lerp_d(ft_get_r(color1), ft_get_r(color2), timestamp);
	g = ft_lerp_d(ft_get_g(color1), ft_get_g(color2), timestamp);
	b = ft_lerp_d(ft_get_b(color1), ft_get_b(color2), timestamp);
	return (create_rgbt(r, g, b, 1));
}

