/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:12:04 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/10 09:48:32 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static inline void	free_map(char **map)
{
	int		i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		ft_strdel(&map[i++]);
	free(map);
}

static inline void	free_imap(int *map[2])
{
	free(map[0]);
	free(map[1]);
}

static inline int	parse_map(t_game *game, char **tab)
{
	if (!(map_begin(tab)))
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

static inline void	gen_free(t_game *game)
{
	free_imap(game->piece);
	free_map(game->map_p);
	free_map(game->map);
	game->map = NULL;
	game->map_p = NULL;
}

int					main(void)
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
		if (parse_map(&game, &tab) == 0)
		{
			put_result(-1, -1);
			return (0);
		}
		if (!(near_enemy(game.map, game.map_y, game.map_x)))
			return (0);
		if (!(opti_place(game.map, &game)))
			return (0);
		put_result(game.valid_y, game.valid_x);
		gen_free(&game);
	}
	return (0);
}
