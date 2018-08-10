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


int	parse_map(t_game *game, char *tab)
{
	if (!(map_begin(&tab)))
		return (0);
	if (!(copy_map(game, game->map_x, game->map_y)))
		return (0);
	if (!(piece_xy(game)))
		return (0);
	if (!(copy_piece(game, game->piece_y)))
		return (0);
	if (!(map_extract_conv(game->map, game, game->map_x, game->map_y)))
		return (0);
	if (!(piece(game->map_p, game)))
		return (0);
	return (1);
}

int			main(void)
{
	char	*tab;
	t_game	game;

	tab = NULL;
	init_struct(&game);
	while (get_next_line(0, &tab))
	{
		// if (game.player == -1)
		// 	if (!get_player_map(&tab, &game))
		// 		return (0);
		// parse_map(&game, tab);
		// if (!(near_enemy(game.map, game.map_y, game.map_x)))
		// 	return (0);
		// if (!(opti_place(game.map, &game)))
		// 	return (0);
		// put_result(game.valid_y, game.valid_x);
	}
	return (0);
}
