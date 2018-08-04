/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:38:15 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/31 20:39:40 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		conv(char c, int y, t_game *g)
{
	if (c == '.')
		return (VOID_VAL);
	else if (is_enemy(c, g))
	{
		if (g->enmy_y_start == -1)
			g->enmy_y_start = y;
		return (ENEMY_VAL);
	}
	else
	{
		if (g->my_y_start == -1)
			g->my_y_start = y;
		return (MY_VAL);
	}
	return (1);
}

int		map_begin(char **tab)
{
	// while (!ft_strstr(*tab, "    0"))
	// {
	// 	printf("GETTING MAP\n");
	// 	ft_memdel((void**)tab);
	// 	get_next_line(0, tab);
	// 	if (!*tab)
	// 	{}
	// 		return (0);
	// }
	if (get_next_line(0, tab) == -1)
		return (ERROR);
	return (1);
}

int		copy_map(t_game *g, int x, int y)
{
	char *tab;
	int i;
	int j;

	i = 0;
	if (!(g->map = (char **)malloc(sizeof(char*) * (y + 1))))
		return (0);
	while (i < y)
	{
		tab = NULL;
		j = 0;
		// printf("while BEFORE \n");
		get_next_line(0, &tab);
		if (!(g->map[i] = (char*)malloc(sizeof(char) * (x + 1))))
			return (0);
		while (j < x)
		{
			g->map[i][j] = tab[j + 4];
			j++;
			// printf("sqdqsdhqkshdqshdiqs \n");
		}
		// printf("while \n");

		g->map[i][j] = '\0';
		// printf("tab= %s, y = %d\n", g->map[i], y);
		if (!tab)
			return (0);
		free(tab);
		i++;
	}
	g->map[i] = NULL;
}

int		copy_piece(t_game *g, int x, int y)
{
	char *tab;
	int i;
	int j;

	i = 0;
	if (!(g->map_p = (char **)malloc(sizeof(char*) * (y + 1))))
		return (0);
	while (i < y)
	{
		tab = NULL;
		// j = 0;
		if (get_next_line(0, &tab) == -1)
			return (0);
		// if (!(g->map_p[i] = (char*)malloc(sizeof(char) * (x + 1))))
		// 	return (0);
		// while (j < x)
		// {
		// 	g->map_p[i] = tab;
		// 	j++;
		// }
		g->map_p[i] = tab;
		// g->map_p[i][j] = '\0';
		// printf("tab= %s, y = %d\n", g->map[i], y);
		// if (!tab)
			// return (0);
		i++;
	}
	g->map_p[i] = NULL;
	// printf("here================\n");
	return (1);
}

void	map_extract_conv(char **tab, t_game *g, int x, int y)
{
	int xx;
	int yy;

	xx = 0;
	yy = 0;
	while (yy < y)
	{
		xx = -1;
		while (++xx < x)
			tab[yy][xx] = conv(tab[yy][xx], yy, g);
		yy++;
	}
}
