/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 00:34:23 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/14 20:10:46 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *k;

	k = (char *)malloc(sizeof(char) * (size + 1));
	if (!k)
		return (NULL);
	ft_bzero(k, size + 1);
	return (k);
}
