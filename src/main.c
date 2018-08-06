/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:12:04 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/04 23:27:50 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			main(void)
{
	char	*tab;
	t_game	game;

	tab = NULL;
	init_struct(&game);
	while (get_next_line(0, &tab))
	{
		if (game.player == -1)
			if (!get_player_map(&tab, &game))
				return (0);
		map_begin(&tab);
		copy_map(&game, game.map_x, game.map_y);
		piece_xy(&game);
		copy_piece(&game, game.piece_x, game.piece_y);
		map_extract_conv(game.map, &game, game.map_x, game.map_y);
		piece(game.map_p, &game);
		near_enemy(game.map, game.map_y, game.map_x, &game);
		opti_place(game.map, &game);
		dprintf(1, "%d %d\n", game.valid_y, game.valid_x);
	}
}
