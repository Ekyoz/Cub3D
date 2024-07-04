/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_rad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:51:36 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/01 16:51:36 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

double	radian_to_degree(double radian)
{
	return (180.0f / PI * radian);
}

double	degree_to_radian(double degree)
{
	return (degree / (180.0f / PI));
}

double	get_angle(t_vector_d start, t_vector_d end)
{
	double	dx;
	double	dy;

	dx = (double)(end.x - start.x);
	dy = (double)(end.y - start.y);
	if (dx >= 0 && dy < 0)
		return (atan(-dy / dx));
	else if (dx < 0 && dy < 0)
		return (atan(dx / dy) + 3.14f / 2.0f);
	else if (dx < 0 && dy > 0)
		return (atan(-dy / dx) + 3.14f);
	else
		return (atan(dx / dy) + 3.14 + 1.57f);
}

double	get_angle_f(t_vector_f start, t_vector_f end)
{
	double	dx;
	double	dy;

	dx = (double)(end.x - start.x);
	dy = (double)(end.y - start.y);
	if (dx >= 0 && dy < 0)
		return (atan(-dy / dx));
	else if (dx < 0 && dy < 0)
		return (atan(dx / dy) + 3.14f / 2.0f);
	else if (dx < 0 && dy > 0)
		return (atan(-dy / dx) + 3.14f);
	else
		return (atan(dx / dy) + 3.14 + 1.57f);
}