/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:12:04 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/04 23:27:50 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(t_game *game)
{
	int x = 0, y = 0;
	int col = 0;

	fprintf(stderr, "\e[100m%4c \e[49m", ' ');
	while (col < game->map_x)
	{
		fprintf(stderr, "\e[100m%2d \e[49m", col);
		col++;
	}
	fprintf(stderr, "\n");
	while(y < game->map_y)
	{
		x = 0;
		fprintf(stderr, "\e[100m[%2d] \e[49m", y);
		while (x < game->map_x)
		{
			if (game->map[y][x] == ENEMY_VAL)
				fprintf(stderr, "\e[101m%2c \e[49m", 'E');
			else if (game->map[y][x] == MY_VAL)
				fprintf(stderr, "\e[102m%2c \e[49m", 'v');
			else if (game->map[y][x] == -7)
				fprintf(stderr, "\e[44m%2c \e[49m", 'V');
			else 
				fprintf(stderr, "\e[106m\e[91m%2c \e[39m\e[49m", '.');
			// printf("%2d ", game->map[y][x]);
			x++;
		}
		y++;
		fprintf(stderr, "\n");
	}
}

void set_pieec(t_game *game, int **piece, int x, int y)
{
	int ii = 0;
	while (ii < game->piece_x)
	{
		if ((y + piece[PIECE_Y][ii] > 0) && (y + piece[PIECE_Y][ii]) < game->map_y \
		&&  (x + piece[PIECE_X][ii] > 0) &&  (x + piece[PIECE_X][ii]) < game->map_x)
			game->map[y + piece[PIECE_Y][ii] ][x + piece[PIECE_X][ii]] = -7;
		ii++;
	}
}


int			main(void)
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
		map_begin(&tab);
		copy_map(&game, game.map_x, game.map_y);
		piece_xy(&game);
		copy_piece(&game, game.piece_x, game.piece_y);
		map_extract_conv(game.map, &game, game.map_x, game.map_y);
		piece(game.map_p, &game);
		// near_enemy(&game, game.map, game.map_y, game.map_x);
		near_enemy(game.map, game.map_y, game.map_x);

		// print_map(&game);
		opti_place(game.map, &game);
		// set_pieec(&game, game.piece, game.valid_x, game.valid_y);
		// print_map(&game);

		// printf("count= %d\n", count_enemy(game.map, &game, 2, 1));
		dprintf(1, "%d %d\n", game.valid_y, game.valid_x);
		// int i = 0;
		// int j;
		// printf("count= %d\n", count_enemy(game.map, &game, 5, 12));
		// while (i < game.map_y)
		// {
		// 	j = 0;
		// 	while (j < game.map_x)
		// 	{
		// 		printf("%2d ", game.map[i][j]);
		// 		j++;
		// 	}
		// 	// printf("NEAR= %s\n", game.map[i]);
		// 	// printf("i = %d, y= %d, x= %d\n", i, game.piece[PIECE_Y][i], game.piece[PIECE_X][i]);
		// 	printf("\n");
		// 	i++;
		// }
	}
}
