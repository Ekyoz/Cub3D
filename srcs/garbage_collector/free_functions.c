/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoyet <bpoyet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:35:04 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/26 17:14:00 by bpoyet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	free_array(char ***ptr)
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
		if((*cub)->texture)
			free_array(&(*cub)->texture);
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

void print_free_exit(char *str, t_pcub *cub)
{
    if(str)
        printf("%s",str);
    free_cub(&cub);
    exit(1);
}
