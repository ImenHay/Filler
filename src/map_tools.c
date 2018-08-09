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
	if (get_next_line(0, tab) == -1)
		return (ERROR);
	ft_memdel((void**)tab);
	return (1);
}

int		map_extract_conv(char **tab, t_game *g, int x, int y)
{
	int xx;
	int yy;

	xx = 0;
	yy = 0;
	if (!tab || x < 0 || y < 0)
		return (ERROR);
	while (yy < y)
	{
		xx = -1;
		while (++xx < x)
			tab[yy][xx] = conv(tab[yy][xx], yy, g);
		yy++;
	}
	return (1);
}
