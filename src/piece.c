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


// int			piece_xy(char **tab, t_game *game)
// {
// 	int		i;
// 	char	**split;

// 	i = 0;
// 	while (tab[i] && !ft_strstr(tab[i], "Piece"))
// 		i++;
// 	if (!tab[i])
// 		return (ERROR);
// 	split = ft_strsplit(tab[i++], ' ');
// 	if (!split[1] || !split[2])
// 		return (ERROR);
// 	game->piece_y = ft_aatoi(split[1]);
// 	game->piece_x = ft_aatoi(split[2]);
// 	free(split);
// 	return (i);
// }

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
	printf("piece= %s\n", tab);
	split = ft_strsplit(tab, ' ');
	if (!split[1] || !split[2])
		return (ERROR);
	game->piece_y = ft_aatoi(split[1]);
	game->piece_x = ft_aatoi(split[2]);
	free(split);
	return (1);
}

// int			count_stars(char **tab, t_game *game, int i)
// {
// 	int		stars;
// 	int		x;
// 	int		y;

// 	x = 0;
// 	y = 0;
// 	stars = 0;
// 	if (!tab || !tab[i])
// 		return (ERROR);
// 	while (y < game->piece_y)
// 	{
// 		x = 0;
// 		while (x < game->piece_x)
// 		{
// 			if (tab[i + y][x] == '*')
// 				stars++;
// 			x++;
// 		}
// 		y++;
// 	}
// 	game->piece_len = stars;
// 	return (1);
// }

// void		piece_coord(char **tab, t_game *game, int i, int stars)
// {
// 	int		j;
// 	int		k;
// 	int		l;

// 	k = -1;
// 	l = 0;
// 	if (!tab || !game)
// 		return ;
// 	if (!(game->piece[PIECE_X] = (int*)malloc(sizeof(int) * stars + 1)))
// 		return ;
// 	if (!(game->piece[PIECE_Y] = (int*)malloc(sizeof(int) * stars + 1)))
// 		return ;
// 	while (++k < game->piece_y)
// 	{
// 		j = 0;
// 		while (j < game->piece_x)
// 		{
// 			if (tab[i + k][j] == '*')
// 			{
// 				game->piece[PIECE_X][l] = j;
// 				game->piece[PIECE_Y][l++] = k;
// 			}
// 			j++;
// 		}
// 	}
// }

// int			piece(char **tab, t_game *game)
// {
// 	if (!tab)
// 		return (ERROR);
// 	game->start_piece = piece_xy(tab, game);
// 	if (!count_stars(tab, game, game->start_piece))
// 		return (ERROR);
// 	piece_coord(tab, game, game->start_piece, game->piece_len);
// 	game->first_px = game->piece[PIECE_X][0];
// 	game->first_py = game->piece[PIECE_Y][0];
// 	return (1);
// }
