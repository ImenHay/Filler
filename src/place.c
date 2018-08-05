/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:04:10 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/04 23:22:02 by imhaimou         ###   ########.fr       */
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
		tmpx = x + (g->piece[PIECE_X][i] - g->piece[PIECE_X][0]);
		tmpy = y + (g->piece[PIECE_Y][i] - g->piece[PIECE_Y][0]);
		if ((check_one_block(tab, tmpy, tmpx, g)) == ERROR)
			return (ERROR);
		if (check_one_block(tab, tmpy, tmpx, g) == 2)
			count++;
		i++;
	}
	// fprintf(stderr, " >>>>>>>>>>. GOT COUNT[%d]\n", count);
	return (count == 1 ? 1 : ERROR);
}

void	relative_position(t_game *g, int tmp, int x, int y)
{
	if (tmp <= count_enemy(g->map, g, x, y))
	{
		tmp = count_enemy(g->map, g, x, y);
		g->valid_x = x - g->first_px;
		g->valid_y = y - g->first_py;
	}
}

// void		opti_place(char **tab, t_game *g)
// {
// 	int		x;
// 	int		y;
// 	char	tmp;

// 	y = 0;
// 	tmp = 0;
// 	static int ii;
// 	// fprintf(stderr, "STATIC : [%d] ----------------------------\n", ii);
// 	ii++;
// 	while (y < g->map_y)
// 	{
// 		x = 0;
// 		while (x < g->map_x)
// 		{
// 			if (tab[y][x] == MY_VAL && check_all(tab, y, x, g) == 1)
// 			{
// 				g->valid_x = x - g->first_px;
// 				g->valid_y = y - g->first_py;

// 				// if (g->my_y_start <= g->enmy_y_start)
// 				// 	relative_position(g, tmp, x, y);
// 			else
// 			{
// 				// printf("--------------------------------\n");
// 				// printf("my_y[%d] enm_y[%d] tmp[%d] count[%d]\n", g->my_y_start , g->enmy_y_start, tmp, count_enemy(tab, g, x, y));
// 				// printf("--------------------------------\n");
// 				if (g->my_y_start > g->enmy_y_start)
// 				{
// 					if (tmp < count_enemy(tab, g, x, y))
// 					{
// 						tmp = count_enemy(tab, g, x, y);
// 						g->valid_x = x - g->first_px;
// 						g->valid_y = y - g->first_py;
// 				// 		// printf("CAME TO CHAGE 01 \n");
// 					}
// 				}
// 				else
// 				{
// 					// fprintf(stderr, "CAME HERE --->>> [%d] \n", count_enemy(tab, g, x, y));
// 					if (tmp <= count_enemy(tab, g, x, y))
// 					{
// 						tmp = count_enemy(tab, g, x, y);
// 						g->valid_x = x - g->first_px;
// 						g->valid_y = y - g->first_py;
// 						// printf("CAME TO CHAGE 02 \n");
// 					}
// 					// fprintf(stderr, "FOUND PLACE \n");
						

// 				}
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	// fprintf(stderr, "exiting static-------------------------------\n");
// }


void		opti_place(char **tab, t_game *g)
{
	int		x;
	int		y;
	char	tmp;

	y = 0;
	tmp = 0;
	init_value(g);
	while (y < g->map_y)
	{
		x = 0;
		while (x < g->map_x)
		{
			if (check_all(tab, y, x, g) == 1)
			{
				if (tmp == 0)
				{
					g->valid_x = x - g->first_px;
					g->valid_y = y - g->first_py;			
				}
				// relative_position(g, tmp, x, y);
				if (tmp < count_enemy(tab, g, x, y))
				{
					tmp = count_enemy(tab, g, x, y);
					g->valid_x = x - g->first_px;
					g->valid_y = y - g->first_py;
				}
			}
			x++;
		}
		y++;
	}
}