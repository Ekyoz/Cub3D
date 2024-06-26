/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atresall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:24:11 by alexandre          #+#    #+#             */
/*   Updated: 2024/06/25 15:24:11 by alexandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cube3d.h"

int main(int argc, char **argv) {
    
    t_pcub *cub;

    cub = init_cub();
    parse_map(cub, argc, argv);
    free_cub(&cub);
    return 0;
}
