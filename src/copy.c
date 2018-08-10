/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 23:17:39 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/04 23:19:13 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			copy_map(t_game *g, int x, int y)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	if (!(g->map = (char **)malloc(sizeof(char*) * (y + 1))))
		return (0);
	tab = NULL;
	while (i < y)
	{
		// tab = NULL;
		j = -1;
		ft_memdel((void**)tab);
		get_next_line(0, &tab);
		if (!(g->map[i] = (char*)malloc(sizeof(char) * (x + 1))))
			return (0);
		while (++j < x)
			g->map[i][j] = tab[j + 4];
		g->map[i][j] = '\0';
		if (!tab)
			return (0);
		ft_strdel(&tab);
		i++;
	}
	g->map[i] = NULL;
	return (1);
}

int			copy_piece(t_game *g, int y)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(g->map_p = (char **)malloc(sizeof(char*) * (y + 1))))
		return (0);
	while (i < y)
	{
		// printf("ici %d\n", i);
		tab = NULL;
		ft_memdel((void**)tab);
		if (get_next_line(0, &tab) == -1)
			return (0);
		g->map_p[i] = ft_strdup(tab);
		ft_strdel(&tab);
		i++;
	}
	g->map_p[i] = NULL;
	return (1);
}
