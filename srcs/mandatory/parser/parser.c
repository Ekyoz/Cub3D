/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastpoy <bastpoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:21:21 by bpoyet            #+#    #+#             */
/*   Updated: 2024/07/05 15:24:32 by bastpoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parse_map(t_pcub *cub, int argc, char **argv)
{
    if(argc != 2)
    {
        print_free_exit(ERROR_ARG, cub);
    }
    cub->filefd = open_file(argv[1], cub);
    get_texture(cub, argv[1]);
    get_height_map(cub);
    close(cub->filefd);
    cub->filefd = open_file(argv[1], cub);
    fill_map(cub);
    get_xy_maxsize(cub);
    check_carac_map(cub);
    check_lines(cub);
    check_player_number(cub);
    complete_map(cub);
    check_closing_map(cub);
}
