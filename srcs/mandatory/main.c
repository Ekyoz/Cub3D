/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandre <atresall@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:24:11 by alexandre          #+#    #+#            */
/*   Updated: 2024/06/25 15:24:11 by alexandre         ###   ########.fr      */
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
