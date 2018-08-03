/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:17:07 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/15 14:50:16 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char		*k;
	size_t		i;
	size_t		j;

	i = 0;
	if (!s)
		return (0);
	j = ft_strlen((char*)s) - 1;
	if (!s)
		return (0);
	while (ft_trim_space(s[i]) && s[i] != '\0')
		i++;
	if (i == ft_strlen((char*)s))
		return (ft_strdup(""));
	while (ft_trim_space(s[j]))
		j--;
	k = ft_strsub(s, i, j - i + 1);
	return (k);
}
