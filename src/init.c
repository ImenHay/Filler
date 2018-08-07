/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:36:41 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/31 20:37:49 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_struct(t_game *game)
{
	game->my_y_start = -1;
	game->enmy_y_start = -1;
	game->valid_x = 0;
	game->valid_y = 0;
	game->player = -1;
	game->piece[0] = NULL;
	game->piece[1] = NULL;
	game->piece_len = 0;
	game->piece_x = 0;
	game->piece_y = 0;
	game->map = NULL;
	game->map_p = NULL;
	game->map_x = -1;
	game->map_y = -1;
	game->first_px = -1;
	game->first_py = -1;
}

void	init_value(t_game *g)
{
	g->valid_x = 0;
	g->valid_y = 0;
}
