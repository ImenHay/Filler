/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 00:42:54 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 21:52:54 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*k;
	size_t	i;

	i = 0;
	if (!s || start > (unsigned int)ft_strlen((char*)s))
		return (NULL);
	k = (char *)malloc(sizeof(char) * (len + 1));
	if (!k)
		return (NULL);
	while (s[start + i] && i < len)
	{
		k[i] = s[start + i];
		i++;
	}
	k[i] = '\0';
	return (k);
}
