/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:36:01 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/31 20:36:32 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_enemy(char **tab, t_game *g)
{
	int block;
	int count;
	int x;
	int y;

	count = 1;
	block = 0;
	while (block < g->piece_len)
	{
		x = g->piece[PIECE_X][block];
		y = g->piece[PIECE_Y][block];
		if (tab[x][y] == NEAR)
			count++;
		block++;
	}
	return (count);
}

int		is_enemy(char c, t_game *g)
{
	if (g->player == 1)
		return((c == 'x' || c == 'X') ? 1 : 0);
	else if (g->player == 2)
		return ((c == 'o' || c == 'O') ? 1 : 0);
	return (1);
}

void	near_enemy(char **tab, int yy, int xx)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (tab[y] && y < yy)
	{
		x = 0;
		while (x < xx)
		{
		// printf("inside neqr enmey \n"); 	
			if (tab[y][x] == ENEMY_VAL)
			{
				if (tab[y - 1][x] == VOID_VAL)
					tab[y - 1][x] = NEAR;
				if (tab[y + 1][x] == VOID_VAL)
					tab[y + 1][x] = NEAR;
				if (tab[y][x - 1] == VOID_VAL)
					tab[y][x - 1] = NEAR;
				if (tab[y][x + 1])
					tab[y][x + 1] = NEAR;
			}
			x++;
		}
		y++;
	}
}
