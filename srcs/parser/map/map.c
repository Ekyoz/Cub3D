/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:02:07 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/09 16:24:07 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	complete_map(t_pcub *cub)
{
	char	*linecp;
	int		i;
	int		j;

	i = 0;
	while (cub->map[i])
	{
		j = ft_strlen1(cub->map[i], cub);
		while (j < cub->x_max_size)
		{
			linecp = cub->map[i];
			cub->map[i] = ft_strjoin(linecp, " ");
			free(linecp);
			j++;
		}
		i++;
	}
}

void	check_player_number(t_pcub *cub)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	if (player < 1)
		print_free_exit(NO_PLAYER, cub);
	if (player > 1)
		print_free_exit(TOO_MANY_PLAYER, cub);
}

void	check_carac_map(t_pcub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		if (!ft_strncmp(cub->map[i], "\n", 2))
			print_free_exit(EMPTY_LINE_END, cub);
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != '0' && cub->map[i][j] != '1'
				&& cub->map[i][j] != 'N' && cub->map[i][j] != ' '
				&& cub->map[i][j] != '\n' && cub->map[i][j] != 'S'
				&& cub->map[i][j] != 'E' && cub->map[i][j] != 'W'
				&& cub->map[i][j] != 'D')
				print_free_exit(WRONG_CARACTER_MAP, cub);
			j++;
		}
		i++;
	}
}

void	fill_map(t_pcub *cub)
{
	char	*line;
	int		i;

	i = 0;
	cub->map = (char **)malloc(sizeof(char *) * (cub->linemap + 1));
	if (!cub->map)
		print_free_exit(ERROR_MALLOC_INIT, cub);
	while (i < cub->linetexture)
	{
		line = get_next_line(cub->filefd);
		free(line);
		i++;
	}
	i = 0;
	while (i < cub->linemap)
	{
		line = get_next_line(cub->filefd);
		if (line)
			cub->map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	cub->map[i] = NULL;
}

void	get_height_map(t_pcub *cub)
{
	char	*line;

	line = get_next_line(cub->filefd);
	while (line)
	{
		cub->linemap++;
		free(line);
		line = get_next_line(cub->filefd);
	}
	printf("le nombre de ligne de map est %d\n", cub->linemap);
	if (cub->linemap == 0)
		print_free_exit(NO_MAP, cub);
}
