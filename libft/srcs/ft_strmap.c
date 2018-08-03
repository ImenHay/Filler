/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 00:38:56 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 21:26:15 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*k;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	k = (char *)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (!k)
		return (NULL);
	while (s[i])
	{
		k[i] = f(s[i]);
		i++;
	}
	k[i] = '\0';
	return (k);
}
