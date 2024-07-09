/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:14:41 by bastpoy           #+#    #+#             */
/*   Updated: 2024/07/09 16:23:13 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	print_free_str_exit(char *errormessage, char *str, t_pcub *cub)
{
	if (errormessage)
		printf("\n\n\033[31m==%s==\033[0m\n\n", errormessage);
	if (str)
		free(str);
	free_cub(&cub);
	exit(0);
}
