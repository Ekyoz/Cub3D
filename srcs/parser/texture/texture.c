/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:57:24 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/10 18:32:04 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

// check la texture actuelle et verifie l'ordre a chaque fois
static void	find_texture(char *str, int j, t_pcub *cub)
{
	if (str[j] == 'N' && str[j + 1] == 'O')
		get_texture_face(cub, str, j, &(cub->notexture));
	else if (str[j] == 'S' && str[j + 1] == 'O')
		get_texture_face(cub, str, j, &(cub->sotexture));
	else if (str[j] == 'W' && str[j + 1] == 'E')
		get_texture_face(cub, str, j, &(cub->wetexture));
	else if (str[j] == 'E' && str[j + 1] == 'A')
		get_texture_face(cub, str, j, &(cub->eatexture));
	else if (str[j] == 'F' && str[j + 1] == ' ')
	{
		if (space_before(str, j))
			get_color_floor(cub, str);
	}
	else if (str[j] == 'C' && str[j + 1] == ' ')
	{
		if (space_before(str, j))
			get_color_ceiling(cub, str);
	}
}

// la je cherche ma texture dans ma ligne
static int	search_texture(char *str, t_pcub *cub, int j)
{
	if (check_cmp(&str[j]))
	{
		find_texture(str, j, cub);
	}
	return (0);
}

// je reitere dans mon fichier pour trouver mes textures
static void	put_texture(t_pcub *cub)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = get_next_line(cub->filefd);
    printf("size %d %s\n", ft_strlen1(str, cub), str);
	while (i < cub->linetexture)
	{
		j = 0;
		while (str[j] && ft_isspace(str[j]))
			j++;
		if (str[j] != '\0')
			search_texture(str, cub, j);
		if (i + 1 == cub->linetexture)
			break ;
		free(str);
		str = get_next_line(cub->filefd);
		i++;
	}
    printf("size %d %s\n", ft_strlen1(str, cub), str);
	free(str);
}

static void	countline_texture(t_pcub *cub)
{
	char	*str;

	str = get_next_line(cub->filefd);
	if (str == NULL)
		print_free_exit(EMPTY_FILE, cub);
	while (str != NULL && !is_map(str))
	{
		cub->linetexture++;
		free(str);
		str = get_next_line(cub->filefd);
	}
	free(str);
	printf("le nombre de ligne de texture est %d\n", cub->linetexture);
	if (cub->linetexture == 0)
		print_free_exit(EMPTY_FILE, cub);
}

void	get_texture(t_pcub *cub, char *argv1)
{
	check_arg_extension(argv1, cub);
	cub->filefd = open_file(argv1, cub);
	countline_texture(cub);
	close(cub->filefd);
	cub->filefd = open_file(argv1, cub);
	put_texture(cub);
	if (cub->counttexture != 6)
		print_free_exit(TEXTURE_NUMBER, cub);
	cub->notexture = check_texture_extension(cub, cub->notexture);
	cub->sotexture = check_texture_extension(cub, cub->sotexture);
	cub->eatexture = check_texture_extension(cub, cub->eatexture);
	cub->wetexture = check_texture_extension(cub, cub->wetexture);
}
