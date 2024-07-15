/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_color_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:32:48 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/09 16:27:12 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_color	*fill_color(t_color *color, char **split_color, int f_or_c)
{
	if (f_or_c == 1)
	{
		color->r_floor = ft_atoi(split_color[0]);
		color->g_floor = ft_atoi(split_color[1]);
		color->b_floor = ft_atoi(split_color[2]);
	}
	else
	{
		color->r_ceiling = ft_atoi(split_color[0]);
		color->g_ceiling = ft_atoi(split_color[1]);
		color->b_ceiling = ft_atoi(split_color[2]);
	}
	return (color);
}

void	get_texture_face(t_pcub *cub, char *str, int j, char **face)
{
	char	*start;
	char	*end;

	if (!space_before(str, j))
		return ;
	start = ft_strchr(str, '.');
	end = ft_strchr(str, '\n');
	if (start && end && space_inside(&str[j + 2], start))
	{
		if (*face)
		{
			free(str);
			print_free_exit(MULTI_TEXTURE, cub);
		}
		*face = ft_substr(str, start - str, end - start);
		if (!(*face))
		{
			free(str);
			print_free_exit(NO_NAME_TEXTURE, cub);
		}
		cub->counttexture++;
	}
	else
		print_free_exit(ERROR_FACE_TEXTURE, cub);
}

void	get_color_ceiling(t_pcub *cub, char *str)
{
	char	*start;
	char	**split_color;
	int		nb;

	nb = 0;
	start = ft_strchr(str, ' ');
	is_valid_color(start, cub);
	split_color = ft_split(start, ',');
	if (!split_color)
		print_free_str_exit(COMB_COLOR, str, cub);
	while (split_color[nb])
		nb += check_space_inside(cub, split_color[nb], split_color, str);
	if (ft_tablen(split_color) == 3 && nb == 3)
		cub->color = fill_color(cub->color, split_color, 0);
	else
	{
		free_array(&split_color);
		print_free_str_exit(TREE_COLOR, str, cub);
	}
	color_hex_ceiling(cub);
	free_array(&split_color);
	if (cub->color->r_ceiling > 255 || cub->color->g_ceiling > 255
		|| cub->color->b_ceiling > 255)
		print_free_exit(COLOR_NUMBER, cub);
	cub->counttexture++;
}

void	get_color_floor(t_pcub *cub, char *str)
{
	char	*start;
	char	**split_color;
	int		nb;

	nb = 0;
	start = ft_strchr(str, ' ');
	is_valid_color(start, cub);
	split_color = ft_split(start, ',');
	if (!split_color)
		print_free_str_exit(COMB_COLOR, str, cub);
	while (split_color[nb])
		nb += check_space_inside(cub, split_color[nb], split_color, str);
	if (ft_tablen(split_color) == 3 && nb == 3)
		cub->color = fill_color(cub->color, split_color, 1);
	else
	{
		free_array(&split_color);
		print_free_str_exit(TREE_COLOR, str, cub);
	}
	color_hex_floor(cub);
	free_array(&split_color);
	if (cub->color->r_floor > 255 || cub->color->g_floor > 255
		|| cub->color->b_floor > 255)
		print_free_exit(COLOR_NUMBER, cub);
	cub->counttexture++;
}
