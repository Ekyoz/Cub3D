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

#include "cube3d.h"

int ft_strlen1(char *str, t_pcub *cub)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
    if(i > 2147483646 || i < 0)
    {
        print_free_exit(MAP_TOO_BIG, cub);
    }
	return (i);
}

int main(int argc, char **argv) {
    
    t_pcub *cub;

    cub = init_cub();
    parse_map(cub, argc, argv);
    free_cub(&cub);
    return 0;
}
