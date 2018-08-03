/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 23:31:29 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 19:17:15 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char k[n];

	if (n < 1024 * 1024 * 128)
	{
		ft_memcpy(k, src, n);
		ft_memcpy(dest, k, n);
		return (dest);
	}
	return (NULL);
}
