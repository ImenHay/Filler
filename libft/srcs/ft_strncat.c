/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:30:33 by imhaimou          #+#    #+#             */
/*   Updated: 2017/04/18 16:59:14 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int len;

	i = 0;
	while (dest[i])
		i++;
	len = i;
	while (src[i - len] && (i - len) < nb)
	{
		dest[i] = src[i - len];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
