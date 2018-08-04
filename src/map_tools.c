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
	while (!ft_strstr(*tab, "    0"))
	{
		ft_memdel((void**)tab);
		get_next_line(0, tab);
		if (!*tab)
			return (0);
	}
	return (1);
}

int		copy(t_game *g, int x, int y)
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
		get_next_line(0, &tab);
		if (!(g->map[i] = (char*)malloc(sizeof(char) * (x + 1))))
			return (0);
		while (j < x)
		{
			g->map[i][j] = tab[j + 4];
			j++;
		}
		g->map[i][j] = '\0';
		// printf("tab= %s, y = %d\n", g->map[i], y);
		free(tab);
		if (!tab)
			return (0);
		i++;
	}
	g->map[i] = NULL;
}

// int		map_extract_conv(char **tab, t_game *g, int x, int y)
// {
// 	int	i;
// 	int	j;
// 	int	k;
// 	int	l;

// 	i = 0;
// 	k = 0;
// tab = NULL;
// 	if (!(g->map = (char**)malloc(sizeof(char*) * (y + 1))))
// 		return (0);
	// y += i;
	// while (i < y)
	// {
// 		get_next_line(0, tab);
// 		if (!(g->map[i] = (char*)malloc(sizeof(char) * (x + 1))))
// 			return (0);
// 		j = 3;
// 		l = 0;
// 		while (j < (x + 4))
// 		{
// 			g->map[i][l] = 'a';
// 			j++;
// 			l++;
// 		}
// 		g->map[i][l] = '\0';
// 		i++;
// 		ft_memdel((void**)tab);
// 		if (!*tab)
// 			return (0);
// 	}
// 	g->map[i] = NULL;
// 	return (1);
// }
