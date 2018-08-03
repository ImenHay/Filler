/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:34:29 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 19:03:19 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *ddest;
	unsigned char *ssrc;

	ddest = (unsigned char*)dest;
	ssrc = (unsigned char*)src;
	while (n--)
	{
		*ddest = *ssrc;
		if (*ssrc == (unsigned char)c)
			return (ddest + 1);
		ssrc++;
		ddest++;
	}
	return (NULL);
}
