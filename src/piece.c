/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 03:47:13 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/31 20:43:22 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			piece_xy(t_game *game)
{
	int		i;
	char	**split;
	char	*tab;

	tab = NULL;
	i = 0;
	if (get_next_line(0, &tab) == 1)
		if (!tab || !ft_strstr(tab, "Piece"))
			return (0);
	split = ft_strsplit(tab, ' ');
	if (!split[1] || !split[2])
		return (ERROR);
	game->piece_y = ft_aatoi(split[1]);
	game->piece_x = ft_aatoi(split[2]);
	ft_memdel((void**)&split[0]);
	ft_memdel((void**)&split[1]);
	ft_memdel((void**)&split[2]);
	ft_memdel((void**)&split);
	ft_strdel(&tab);
	return (1);
}

int			count_stars(char **tab, t_game *game, int i)
{
	int		stars;
	int		x;
	int		y;

	x = 0;
	y = 0;
	stars = 0;
	if (!tab || !tab[i])
		return (ERROR);
	while (y < game->piece_y)
	{
		x = 0;
		while (x < game->piece_x)
		{
			if (tab[i + y][x] == '*')
				stars++;
			x++;
		}
		y++;
	}
	game->piece_len = stars;
	return (1);
}

int			piece_coord(char **tab, t_game *g, int i, int stars)
{
	int		j;
	int		k;
	int		l;

	k = -1;
	l = 0;
	if (!tab || !g)
		return (ERROR);
	if (!(g->piece[0] = (int *)malloc(sizeof(int) * (stars + 1))))
		return (ERROR);
	if (!(g->piece[1] = (int *)malloc(sizeof(int) * (stars + 1))))
		return (ERROR);
	while (++k < g->piece_y)
	{
		j = -1;
		while (++j < g->piece_x)
		{
			if (tab[i + k][j] == '*')
			{
				g->piece[PIECE_X][l] = j;
				g->piece[PIECE_Y][l++] = k;
			}
		}
	}
	return (1);
}

int			piece(char **tab, t_game *game)
{
	if (!tab)
		return (ERROR);
	if (!(count_stars(tab, game, 0)))
		return (ERROR);
	if (!(piece_coord(tab, game, 0, game->piece_x * game->piece_y)))
		return (ERROR);
	game->first_px = game->piece[PIECE_X][0];
	game->first_py = game->piece[PIECE_Y][0];
	return (1);
}
