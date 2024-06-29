/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:29:48 by bpoyet            #+#    #+#             */
/*   Updated: 2024/06/29 15:36:39 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int open_file(char *argv1, t_pcub *cub)
{
    int fd;

    fd = open(argv1, O_RDONLY);
    if(fd == -1)
    {
        print_free_exit(ERROR_OPEN_FILE, cub);
    }
    return fd;
}