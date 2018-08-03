/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:44:50 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/15 16:49:36 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	a;
	char	*s1;
	char	*s2;

	s1 = (char*)ft_memchr(dst, '\0', len);
	if (!s1)
		return (len + ft_strlen((char*)src));
	s2 = (char*)src;
	a = ft_strlen((char*)dst) + ft_strlen((char*)src);
	while ((size_t)(s1 - dst) < len - 1 && *s2)
		*(s1++) = *(s2++);
	*s1 = '\0';
	return (a);
}
