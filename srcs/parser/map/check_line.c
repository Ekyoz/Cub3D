/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 20:30:51 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/09 16:58:26 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	check_first_line(t_pcub *cub)
{
	int	x;

	x = 0;
	while (cub->map[0][x])
	{
		if (cub->map[0][x] != '1' && cub->map[0][x] != '\n'
			&& cub->map[0][x] != ' ')
		{
			print_free_exit(MAP_NOT_CLOSED, cub);
		}
		x++;
	}
}

static void	check_last_line(t_pcub *cub)
{
	int	x;

	x = 0;
	while (cub->map[cub->linemap - 1][x])
	{
		if (cub->map[cub->linemap - 1][x] != '1' && cub->map[cub->linemap
			- 1][x] != '\n' && cub->map[cub->linemap - 1][x] != ' ')
		{
			print_free_exit(MAP_NOT_CLOSED, cub);
		}
		x++;
	}
}

static void	check_first_colonne(t_pcub *cub)
{
	int	i;

	i = 0;
	while (cub->map[i])
	{
		if (cub->map[i][0] != '1' && cub->map[i][0] != '\n'
			&& cub->map[i][0] != ' ')
			print_free_exit(MAP_NOT_CLOSED, cub);
		i++;
	}
}

void	check_lines(t_pcub *cub)
{
	check_first_line(cub);
	check_last_line(cub);
	check_first_colonne(cub);
}
