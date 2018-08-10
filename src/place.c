/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:04:10 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/10 09:50:12 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_one_block(char **tab, int y, int x, t_game *g)
{
	if (x < 0 || y < 0 || (x >= g->map_x) || (y >= g->map_y))
		return (ERROR);
	if (tab[y][x] == ENEMY_VAL)
		return (ERROR);
	if (tab[y][x] == MY_VAL)
		return (2);
	return (1);
}

int			check_all(char **tab, int y, int x, t_game *g)
{
	int		i;
	int		tmpx;
	int		tmpy;
	int		count;

	i = 0;
	count = 0;
	tmpx = 0;
	tmpy = 0;
	while (i < g->piece_len)
	{
		tmpx = x + (g->piece[PIECE_X][i] - g->piece[PIECE_X][0]);
		tmpy = y + (g->piece[PIECE_Y][i] - g->piece[PIECE_Y][0]);
		if ((check_one_block(tab, tmpy, tmpx, g)) == ERROR)
			return (ERROR);
		if (check_one_block(tab, tmpy, tmpx, g) == 2)
			count++;
		i++;
	}
	return (count == 1 ? 1 : ERROR);
}

void		relative_position(t_game *g, int tmp, int x, int y)
{
	if (tmp <= count_enemy(g->map, g, x, y))
	{
		tmp = count_enemy(g->map, g, x, y);
		g->valid_x = x - g->first_px;
		g->valid_y = y - g->first_py;
	}
}

int			opti_place(char **tab, t_game *g)
{
	int		x;
	int		y;
	char	tmp;

	y = -1;
	tmp = 0;
	if (!tab)
		return (0);
	init_value(g);
	while (++y < g->map_y)
	{
		x = -1;
		while (++x < g->map_x)
			if (check_all(tab, y, x, g) == 1)
			{
				relative_position(g, tmp, x, y);
				if (tmp < count_enemy(tab, g, x, y))
				{
					tmp = count_enemy(tab, g, x, y);
					g->valid_x = x - g->first_px;
					g->valid_y = y - g->first_py;
				}
			}
	}
	return (1);
}
