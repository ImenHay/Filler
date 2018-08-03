/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:21:14 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 20:30:23 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int len;

	i = 0;
	i = ft_strlen(dest);
	len = i;
	while (src[i - len] != '\0')
	{
		dest[i] = src[i - len];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
