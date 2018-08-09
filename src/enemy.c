/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:36:01 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/06 04:33:03 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					count_enemy(char **tab, t_game *g, int xx, int yy)
{
	int block;
	int count;
	int x;
	int y;

	x = 0;
	y = 0;
	count = 1;
	block = 0;
	while (block < g->piece_len)
	{
		x = xx + (g->piece[PIECE_X][block] - g->piece[PIECE_X][0]);
		y = yy + (g->piece[PIECE_Y][block] - g->piece[PIECE_Y][0]);
		if ((x < 0 || x > g->map_x) || (y < 0 || y > g->map_y))
			return (0);
		if ((x < g->map_x) && (y < g->map_y) && tab[y] && tab[y][x] == NEAR)
			count++;
		block++;
	}
	return (count);
}

int					is_enemy(char c, t_game *g)
{
	if (g->player == 1)
		return ((c == 'x' || c == 'X') ? 1 : 0);
	else if (g->player == 2)
		return ((c == 'o' || c == 'O') ? 1 : 0);
	return (1);
}

static inline void	around(char **tab, int y, int x)
{
	if (tab[y - 1][x + 1] == VOID_VAL)
		tab[y - 1][x + 1] = NEAR;
	if (tab[y + 1][x + 1] == VOID_VAL)
		tab[y + 1][x + 1] = NEAR;
	if (tab[y - 1][x - 1] == VOID_VAL)
		tab[y - 1][x - 1] = NEAR;
	if (tab[y + 1][x - 1] == VOID_VAL)
		tab[y + 1][x - 1] = NEAR;
	if (tab[y - 1][x] == VOID_VAL)
		tab[y - 1][x] = NEAR;
	if (tab[y + 1][x] == VOID_VAL)
		tab[y + 1][x] = NEAR;
	if (tab[y][x - 1] == VOID_VAL)
		tab[y][x - 1] = NEAR;
	if (tab[y][x + 1] == VOID_VAL)
		tab[y][x + 1] = NEAR;
}

int				near_enemy(char **tab, int yy, int xx)
{
	int x;
	int y;

	y = 1;
	if (!tab || yy < 0 || xx < 0)
		return (ERROR);
	while (y < yy - 1)
	{
		x = 1;
		while (x < xx - 1)
		{
			if (tab[y][x] == ENEMY_VAL)
				around(tab, y, x);
			x++;
		}
		y++;
	}
	return (1);
}
