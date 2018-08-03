/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 00:45:24 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/14 17:51:23 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		word;
	int		i;
	int		size;

	i = 0;
	if (!s || !c)
		return (0);
	word = ft_count_word((char*)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (word) + 1)))
		return (NULL);
	while (i < word)
	{
		while (*s == c && *s != '\0')
			s++;
		size = ft_size((char*)s, c);
		if (!(tab[i] = ft_strsub(s, 0, size)))
			return (NULL);
		s += size + 1;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
