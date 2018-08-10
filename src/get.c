/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 03:37:44 by imhaimou          #+#    #+#             */
/*   Updated: 2018/08/04 23:20:11 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			get_player(char **tab, t_game *game)
{
	char *tmp;
	if (!*tab)
		return (0);
	if (ft_strstr(*tab, "exec p"))
	{
		tmp = strdup(*tab);
		game->player = ft_aatoi(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

void		free_tab(char **tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_memdel((void**)&tab[i]);
		i++;
	}
	ft_memdel((void**)&tab);
}


int			get_map_size(char **tab, t_game *game)
{
	char	**split;

	split = NULL;
	while (!ft_strstr(*tab, "Plateau"))
	{
		ft_memdel((void**)tab);
		get_next_line(0, tab);
		if (*tab == NULL)
			return (0);
	}
	if ((split = ft_strsplit(*tab, ' ')))
	{
		game->map_y = ft_aatoi(split[1]);
		game->map_x = ft_aatoi(split[2]);
		ft_memdel((void**)&split[0]);
		ft_memdel((void**)&split[1]);
		ft_memdel((void**)&split[2]);
		ft_memdel((void**)&split);
		ft_memdel((void**)tab);
		return (1);
	}
	return (0);
}

int			get_player_map(char **tab, t_game *game)
{
	if (!(get_player(tab, game)))
		return (ERROR);
	if (!get_map_size(tab, game))
		return (ERROR);
	return (1);
}
