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
	while (!ft_strstr(*tab, "000 "))
	{
		ft_memdel((void**)tab);
		get_next_line(0, tab);
		if (!*tab)
			return (0);
	}
	return (1);
}

int		map_extract_conv(char **tab, t_game *g, int x, int y)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	k = 0;
	if (!(g->map = (int**)malloc(sizeof(int*) * (y + 1))))
		return (0);
	map_begin(tab);
	y += i;
	while (i < y)
	{
		if (!(g->map[i] = (int*)malloc(sizeof(int) * (x + 1))))
			return (0);
		j = 3;
		l = 0;
		while (++j < (x + 4))
			g->map[i][l++] = tab[0][j];
		g->map[i][l] = '\0';
		i++;
		ft_memdel((void**)tab);
		get_next_line(0, tab);
		if (!*tab)
			return (0);
	}
	g->map[k] = NULL;
	return (1);
}
