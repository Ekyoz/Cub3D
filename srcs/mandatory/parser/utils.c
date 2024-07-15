/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:30:10 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/09 14:51:25 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if ((str[i] == '1' || str[i] == '0'))
		{
			j = 0;
			while (j < i && ft_isspace(str[j]))
				j++;
			if (j == i)
				return (true);
		}
		if (str[i] == '\0')
			return (false);
		i++;
	}
	return (false);
}

bool	space_before(char *str, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			return (false);
		}
		i++;
	}
	return (true);
}

bool	space_inside(char *start, char *end)
{
	int	i;
	int	j;

	j = 0;
	i = end - start;
	while (j < i)
	{
		if (start[j] != ' ' && start[j] != '\t')
		{
			return (false);
		}
		j++;
	}
	return (true);
}

int	open_file(char *argv1, t_pcub *cub)
{
	int	fd;

	fd = open(argv1, O_RDONLY);
	if (fd == -1)
	{
		print_free_exit(ERROR_OPEN_FILE, cub);
	}
	return (fd);
}
