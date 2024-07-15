/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 08:08:17 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/05 17:33:28 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cmp(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0
		|| ft_strncmp(line, "DO", 2) == 0)
		return (1);
	return (0);
}

void	check_arg_extension(char *argv1, t_pcub *cub)
{
	char	*str;

	str = ft_strnstr(argv1, ".cub", ft_strlen(argv1));
	if (str == NULL || ft_strlen(str) != 4)
	{
		print_free_exit(ERROR_TEXTURE_EXT, cub);
	}
}

char	**init_texture(t_pcub *cub)
{
	char	**texture;
	int		i;

	i = 0;
	texture = (char **)malloc(sizeof(char *) * 5);
	if (!texture)
		print_free_exit(ERROR_MALLOC_INIT, cub);
	while (i < 5)
	{
		texture[i] = NULL;
		i++;
	}
	return (texture);
}

void	texture_in_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		i++;
	}
}

char	*check_texture_extension(t_pcub *cub, char *texture)
{
	int		length;
	char	*trimspace;
	char	*test;
	char	*texturecp;

	length = ft_strlen(texture);
	if (length < 4)
		print_free_exit(TEXTURE_PROBLEM, cub);
	trimspace = ft_strnstr(texture, ".xpm", length);
	if (trimspace)
	{
		test = trimspace + 4;
		while (*test)
		{
			while (*test && ft_isspace(*test))
				test++;
			if (*test)
				print_free_exit(TEXTURE_PROBLEM, cub);
		}
	}
	else
		print_free_exit(TEXTURE_PROBLEM, cub);
	texturecp = ft_substr(texture, 0, trimspace + 4 - texture);
	free(texture);
	return (texturecp);
}
