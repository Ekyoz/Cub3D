/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:44:49 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/11 14:44:49 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_vector_d	create_vect_d_from_origin(t_vector_d origin, float radian,
										float length)
{
	t_vector_d	vector;

	vector.x = cos(-radian) * length + origin.x;
	vector.y = sin(-radian) * length + origin.y;
	return (vector);
}

t_vector_d	create_d_vect(int x, int y)
{
	t_vector_d	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector_f	create_f_vect(float x, float y)
{
	t_vector_f	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

void	set_vector_d(t_vector_d *vector, int x, int y)
{
	vector->x = x;
	vector->y = y;
}

t_vector_f	vector_f_lerp(t_vector_f start, t_vector_f end, float timestamp)
{
	t_vector_f	vector;
	float		dx;
	float		dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	vector.x = start.x + dx * timestamp;
	vector.y = start.y + dy * timestamp;
	return (vector);
}
