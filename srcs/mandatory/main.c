/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atresall <atresall@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:01:07 by atresall          #+#    #+#             */
/*   Updated: 2024/07/15 20:01:15 by atresall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_pcub	*p_cub;
	t_cub	cub;

	p_cub = init_cub();
	parse_map(p_cub, argc, argv);
	cub.map = init_map();
	put_cub_in_map(&p_cub, &cub.map);
	init_game(&cub);
	init_input(&cub.mouse, &cub.keyboard);
	if (init_sprites(&cub) == 1)
		close_cub(&cub, ERROR_SPRITE, 1);
	if (init_player(&cub) == 1)
		close_cub(&cub, ERROR_PLAYER, 1);
	loop(&cub);
	close_cub(&cub, NULL, 0);
}
