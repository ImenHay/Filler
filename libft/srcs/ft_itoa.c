/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <imhaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:18:49 by imhaimou          #+#    #+#             */
/*   Updated: 2018/05/15 01:06:32 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbsize(int nb)
{
	int size;

	size = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char	*k;
	int		size;
	int		negatif;

	negatif = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		negatif = 1;
	}
	size = ft_nbsize(n);
	k = (char *)malloc(sizeof(char) * (size + 1 + negatif));
	if (!k)
		return (NULL);
	if (negatif == 1)
		k[0] = '-';
	k[size-- + negatif] = '\0';
	while (size >= 0)
	{
		k[size-- + negatif] = n % 10 + '0';
		n = n / 10;
	}
	return (k);
}
