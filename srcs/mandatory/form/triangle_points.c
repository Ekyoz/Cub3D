/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:39:34 by alexandre         #+#    #+#             */
/*   Updated: 2024/07/09 17:39:34 by alexandre        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_get_min_3_d(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

static void	ft_swap_v2_d(t_vector_d *a, t_vector_d *b)
{
	t_vector_d	temp;

	set_vector_d(&temp, a->x, a->y);
	set_vector_d(a, b->x, b->y);
	set_vector_d(b, temp.x, temp.y);
}

void	sort_points(t_vector_d *points[3])
{
	t_vector_d	*p0;
	t_vector_d	*p1;
	t_vector_d	*p2;

	p0 = (*points);
	p1 = (*points + 1);
	p2 = (*points + 2);
	if (ft_get_min_3_d(p0->y, p1->y, p2->y) != p0->y)
	{
		if (p1->y < p2->y)
			ft_swap_v2_d(p0, p1);
		else
			ft_swap_v2_d(p0, p2);
	}
	if (p1->y > p2->y)
		ft_swap_v2_d(p1, p2);
}
