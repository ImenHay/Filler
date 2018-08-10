/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:50:35 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/10 10:14:35 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_MAP_VAL	'-'
# define DEFAULT_ENM_VAL	0

# define VOID_VAL	0
# define ENEMY_VAL	1
# define MY_VAL		-1
# define NEAR		2

# define ERROR      -1
# define FT_STDIN	0
# define FT_STDOUT	1
# define FT_STDERR	2

# define PIECE_X 	0
# define PIECE_Y 	1

typedef struct	s_game
{
	int			my_y_start;
	int			enmy_y_start;
	int			valid_x;
	int			valid_y;
	int			player;
	int			*piece[2];
	int			piece_len;
	int			piece_x;
	int			piece_y;
	int			**map_conv;
	char		**map;
	char		**map_p;
	int			map_x;
	int			map_y;
	int			first_px;
	int			first_py;
}				t_game;

int				check_all(char **tab, int y, int x, t_game *g);

int				check_one_block(char **tab, int y, int x, t_game *g);

int				count_enemy(char **tab, t_game *g, int x, int y);

int				count_stars(char **tab, t_game *game, int i);

int				conv(char c, int y, t_game *g);

int				copy_piece(t_game *g, int y);

int				copy_map(t_game *g, int x, int y);

int				ft_aatoi(char *str);

int				ft_abs(int n);

int				get_map_size(char **line, t_game *game);

int				get_next_line(const int fd, char **line);

int				get_player(char **tab, t_game *game);

int				get_player_map(char **tab, t_game *game);

void			init_struct(t_game *game);

int				init_game(char **tab, t_game *game);

void			init_value(t_game *g);

int				is_enemy(char c, t_game *g);

int				map_begin(char **tab);

int				map_extract_conv(char **tab, t_game *g, int x, int y);

int				near_enemy(char **tab, int yy, int xx);

int				opti_place(char **tab, t_game *g);

int				piece_xy(t_game *game);

int				piece_coord(char **tab, t_game *game, int i, int stars);

int				piece(char **tab, t_game *game);

void			put_result(int y, int x);

char			**read_vm();

void			relative_position(t_game *g, int tmp, int x, int y);

#endif
