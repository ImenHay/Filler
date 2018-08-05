/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:36:01 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/04 23:19:36 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_enemy(char **tab, t_game *g, int x, int y)
{
	int block;
	int count;

	int xx;
	int yy;

	xx = 0;
	yy = 0;
	count = 1;
	block = 0;
	while (block < g->piece_len)
	{
		xx = x + (g->piece[PIECE_X][block] - g->piece[PIECE_X][0]);
		yy = y + (g->piece[PIECE_Y][block] - g->piece[PIECE_Y][0]);
		if ((xx < 0 || xx > g->map_x) || (yy < 0 || yy > g->map_y))
			return (0);
		if ((xx > 0 && xx < g->map_x) && (yy > 0 && yy < g->map_y) && tab[yy] && tab[yy][xx] == NEAR)
		{
			// printf("---BOUCLE  x= %d, y= %d, count= %d\n", xx, yy, count);
			count++;
		}
		block++;
	}
	return (count);
}


int		is_enemy(char c, t_game *g)
{
	if (g->player == 1)
		return ((c == 'x' || c == 'X') ? 1 : 0);
	else if (g->player == 2)
		return ((c == 'o' || c == 'O') ? 1 : 0);
	return (1);
}

// void	near_enemy(t_game *g, char **tab, int yy, int xx)
// {
// 	int x;
// 	int y;

// 	x = 0;
// 	y = 0;
// 	while (tab[y] && y < yy)
// 	{
// 		x = 0;
// 		while (x < xx)
// 		{
// 			if (tab[y] && tab[y][x] == ENEMY_VAL)
// 			{
// 				if ((x  -1 > 0 && x - 1 < g->map_x) && (y - 1 > 0 && y - 1  < g->map_y) && tab[y -1] &&  tab[y - 1][x + 1] == VOID_VAL)
// 					tab[y - 1][x - 1] = NEAR;
// 				if ((x - 1 > 0 && x - 1 < g->map_x) && (y + 1 > 0 && y + 1 < g->map_y) && tab[y + 1] && tab[y + 1][x + 1] == VOID_VAL)
// 					tab[y + 1][x - 1] = NEAR;
// 				if ((x > 0 && x < g->map_x) && (y - 1 > 0 && y - 1 < g->map_y) && tab[y - 1] && tab[y - 1][x] == VOID_VAL)
// 					tab[y - 1][x] = NEAR;
// 				if ((x > 0 && x < g->map_x) && (y + 1 > 0 && y + 1 < g->map_y) && tab[y + 1] && tab[y + 1][x] == VOID_VAL)
// 					tab[y + 1][x] = NEAR;
// 				if ((x - 1 > 0 && x - 1 < g->map_x) && (y > 0 && y < g->map_y) && tab[y] && tab[y][x - 1] == VOID_VAL)
// 					tab[y][x - 1] = NEAR;
// 				if ((x + 1 > 0 && x + 1 < g->map_x) && (y > 0 && y < g->map_y) && tab[y] && tab[y][x + 1])
// 					tab[y][x + 1] = NEAR;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

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
            if (tab[y][x] == ENEMY_VAL)
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
			x++;
		}
		y++;
	}
}