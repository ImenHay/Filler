/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:04:10 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/31 20:48:00 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_one_block(char **tab, int y, int x, t_game *g)
{
	if ((x >= g->map_x) || (y >= g->map_y))
		return (ERROR);
	if (x < 0 || y < 0)
		return (ERROR);
	if (tab[y][x] == ENEMY_VAL)
		return (ERROR);
	if (tab[y][x] == MY_VAL)
		return (2);
	return (1);
}

int		check_all(char **tab, int y, int x, t_game *g)
{
	int	i;
	int	tmpx;
	int	tmpy;
	int	count;

	i = 0;
	count = 0;
	tmpx = 0;
	tmpy = 0;
	while (i < g->piece_len)
	{
		tmpx = x + (g->piece[PIECE_X][i] - g->first_px);
		tmpy = y + (g->piece[PIECE_Y][i] - g->first_py);
		if ((check_one_block(tab, tmpy, tmpx, g)) == ERROR)
		{
			// printf("HERE [%d] [X][%d] [Y][%d] [TX][%d] [TY][%d]\n", ll, tmpy, tmpx, ( g->fx), ( g->fy));
			//  printf("ERROR tmpY = %d, tmpX = %d, i= %d, count= %d / x= %d / y =%d\n", tmpy, tmpx, i, count, x, y);
			return (ERROR);
		}
		if (check_one_block(tab, tmpy, tmpx, g) == 2)
		{
			count++;
			//  printf("COUNT++: Y = %d, X = %d, i= %d, count= %d\n", tmpy, tmpx, i, count);
		}
		i++;
	}
	return (count == 1 ? 1 : 0);
}

void	relative_position(t_game *g, int tmp, int x, int y)
{
	if (g->my_y_start < g->enmy_y_start)
	{
		if (tmp == count_enemy(g->map, g))
		{
			tmp = count_enemy(g->map, g);
			g->valid_x = x - g->first_px;
			g->valid_y = y - g->first_py;
		}
	}
}

void	opti_place(char **tab, t_game *g)
{
	int	x;
	int	y;
	char	tmp;

	y = 0;
	tmp = 0;
	while (y < g->map_y)
	{
		x = 0;
		while (x < g->map_x)
		{
			if (check_all(tab, y, x, g) == 1)
			{
				relative_position(g, tmp, x, y);
				if (tmp < count_enemy(tab, g))
				{
					tmp = count_enemy(tab, g);
                    // printf("TMP = %d, X= %d, Y= %d\n", tmp, x, y);
					g->valid_x = x - g->first_px;
					g->valid_y = y - g->first_py;
				}
			}
			x++;
		}
		y++;
	}
}
