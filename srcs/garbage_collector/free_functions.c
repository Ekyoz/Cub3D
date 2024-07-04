/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:35:04 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/04 16:11:34 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	free_array(char ***ptr)
{
	int	i;

	i = 0;
	if (*ptr)
	{
		while ((*ptr)[i])
		{
			if ((*ptr)[i])
				free((*ptr)[i]);
			(*ptr)[i] = NULL;
			i++;
		}
		free(*ptr);
		*ptr = NULL;
	}
}

void free_cub(t_pcub **cub)
{
	if(*cub)
	{
		if((*cub)->color)
			free_color(&(*cub)->color);
		if((*cub)->notexture)
			free((*cub)->notexture);
		if((*cub)->sotexture)
			free((*cub)->sotexture);
		if((*cub)->eatexture)
			free((*cub)->eatexture);
		if((*cub)->wetexture)
			free((*cub)->wetexture);
		if((*cub)->map)
			free_array(&(*cub)->map);
		if((*cub)->filefd != -1)
		{
			close((*cub)->filefd);
    		(*cub)->filefd = -1;
		}
		free(*cub);
		*cub = NULL;
	}
}

void free_map(t_map **map)
{
	if(*map)
	{
		if((*map)->map)
			free_array(&(*map)->map);
		if((*map)->NO)
			free((*map)->NO);
		if((*map)->SO)
			free((*map)->SO);
		if((*map)->WE)
			free((*map)->WE);
		if((*map)->EA)
			free((*map)->EA);	
		free(*map);
		*map = NULL;
	}
}

void free_color(t_color **color)
{
	if(*color)
	{
		free(*color);
		*color = NULL;
	}
}

void print_free_exit(char *str, t_pcub *cub)
{
    if(str)
        printf("%s",str);
    free_cub(&cub);
    exit(1);
}
