/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 04:12:04 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/25 04:13:28 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(t_game *game)
{
	int x = 0, y = 0;
	int col = 0;

	printf("\e[100m%4c \e[49m", ' ');
	while (col < game->map_x)
	{
		printf("\e[100m%2d \e[49m", col);
		col++;
	}
	printf("\n");
	while(y < game->map_y)
	{
		x = 0;
		printf("\e[100m[%2d] \e[49m", y);
		while (x < game->map_x)
		{
			if (game->map[y][x] == ENEMY_VAL)
				printf("\e[101m%2c \e[49m", 'E');
			else if (game->map[y][x] == MY_VAL)
				printf("\e[102m%2c \e[49m", 'v');
			else if (game->map[y][x] == -7)
				printf("\e[44m%2c \e[49m", 'V');
			else 
				printf("\e[106m\e[91m%2c \e[39m\e[49m", '.');
			// printf("%2d ", game->map[y][x]);
			x++;
		}
		y++;
		printf("\n");
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

int				main()
{
	char		*tab;
	t_game		game;
	int i = 0;
	int j;
	// char		*line;

	tab = NULL;
	// get_player_map(&tab, &game);
	// 	return (0);
	init_struct(&game);
	while (get_next_line(0, &tab))
	{
		if (game.player == -1)
			get_player_map(&tab, &game);
		map_begin(&tab);
		copy_map(&game, game.map_x, game.map_y);
		piece_xy(&game);
		copy_piece(&game, game.piece_x, game.piece_y);
		map_extract_conv(game.map, &game, game.map_x, game.map_y);
		printf("player = %d, x= %d, y= %d, px= %d, py= %d\n", game.player, game.map_x, game.map_y, game.piece_x, game.piece_y);
		piece(game.map_p, &game);
		printf("stars= %d\n", game.piece_len);
		// map_extract_conv(tab, &game, game.map_x, game.map_y);
		near_enemy(game.map);
		// opti_place(game.map, &game);

		// print_map(&game);
		// set_pieec(&game, game.piece, game.valid_x, game.valid_y);
		// print_map(&game);
		// printf("MY y_start= %d, y_enemy %d\n", game.my_y_start, game.enmy_y_start);
		// printf("X= %d, Y= %d // fx= %d, fy = %d\n", game.valid_x, game.valid_y, game.first_px, game.first_py);
		// printf("is_enemy = %d\n", is_enemy(game.map[1][2], &game));
		// while(i < game.piece_y)
		// {
		// 	j = 0;
		// 	// printf("map= %s\n", game.map[i]);
		// 	while (j < game.piece_x)
		// 	{
		// 		printf("%2d ", game.piece[i][j]);
		// 		j++;
		// 	}
		// 	printf("\n");
		// 	i++;
		// }
		while(i < game.map_y)
		{
			j = 0;
			// printf("map= %s\n", game.map[i]);
			while (j < game.map_x)
			{
				printf("%2d ", game.map[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}

