/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:46:58 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/05 18:58:38 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vector_f	vector_d_to_f(t_vector_d vector_d)
{
	t_vector_f	vector_f;

	vector_f.x = vector_d.x;
	vector_f.y = vector_d.y;
	return (vector_f);
}

t_vector_d	vector_f_to_d(t_vector_f vector_f)
{
	t_vector_d	vector_d;

	vector_d.x = vector_f.x;
	vector_d.y = vector_f.y;
	return (vector_d);
}

float	len_squared(t_vector_d start, t_vector_d end)
{
	int	dx;
	int	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	return ((float)(dx * dx) + (float)(dy * dy));
}

double	get_vector_f_length(t_vector_f start, t_vector_f end)
{
	double	dx;
	double	dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
	return (sqrt(dx * dx + dy * dy));
}

t_vector_f	create_vect_f_from_origin(t_vector_f origin, double radian,
		double length)
{
	t_vector_f	vector;

	vector.x = cos(-radian) * length + origin.x;
	vector.y = sin(-radian) * length + origin.y;
	return (vector);
}
