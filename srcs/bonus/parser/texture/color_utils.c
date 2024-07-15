/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:46:21 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/09 14:42:11 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
	}
	return (i);
}

void	color_hex_floor(t_pcub *cub)
{
	cub->color->floor = ((cub->color->r_floor & 0xff) << 16)
		+ ((cub->color->g_floor & 0xff) << 8) + (cub->color->b_floor & 0xff);
}

void	color_hex_ceiling(t_pcub *cub)
{
	cub->color->ceiling = ((cub->color->r_ceiling & 0xff) << 16)
		+ ((cub->color->g_ceiling & 0xff) << 8)
		+ (cub->color->b_ceiling & 0xff);
}

void	is_valid_color(char *str, t_pcub *cub)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == ',' || (str[i] >= '0'
				&& str[i] <= '9') || str[i] == '\n')
			i++;
		else
		{
			free(str);
			print_free_exit(BAD_COLOR, cub);
		}
		if (str[i] != '\0')
			i++;
	}
}

int	check_space_inside(t_pcub *cub, char *str, char **split_color, char *line)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		if ((str[i] >= '0' && str[i] <= '9' && str[i + 1] == ' ')
			|| (str[i] >= '0' && str[i] <= '9' && str[i + 1] == '\t'))
		{
			if (line)
			{
				free(line);
				line = NULL;
			}
			free_array(&split_color);
			print_free_exit(BAD_COLOR, cub);
		}
		i++;
	}
	return (1);
}
