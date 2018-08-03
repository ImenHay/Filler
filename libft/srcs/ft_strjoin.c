/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:12:27 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 21:39:54 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*k;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	k = (char *)malloc(sizeof(char) * (i + 1));
	if (!k)
		return (NULL);
	ft_strcat(ft_strcpy(k, (char*)s1), (char*)s2);
	return (k);
}
