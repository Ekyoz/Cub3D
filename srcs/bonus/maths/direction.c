/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:14:49 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 17:14:49 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	get_direction(t_vector_d start, t_vector_d end)
{
	double	dx;
	double	dy;

	dx = (double)(end.x - start.x);
	dy = (double)(end.y - start.y);
	if (dx >= 0 && dy < 0)
		return (atan(-dy / dx));
	else if (dx < 0 && dy < 0)
		return (atan(dx / dy) + PI / 2.0f);
	else if (dx < 0 && dy > 0)
		return (atan(-dy / dx) + PI);
	else
		return (atan(dx / dy) + PI + PI_2);
}

double	get_direction_f(t_vector_f start, t_vector_f end)
{
	double	dx;
	double	dy;

	dx = (double)(end.x - start.x);
	dy = (double)(end.y - start.y);
	if (dx >= 0 && dy < 0)
		return (atan(-dy / dx));
	else if (dx < 0 && dy < 0)
		return (atan(dx / dy) + PI / 2.0f);
	else if (dx < 0 && dy > 0)
		return (atan(-dy / dx) + PI);
	else
		return (atan(dx / dy) + PI + PI_2);
}
