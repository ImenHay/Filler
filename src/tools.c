/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:48:54 by imhaimou          #+#    #+#             */
/*   Updated: 2018/07/31 20:50:02 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int					ft_aatoi(char *str)
{
	int				i;
	unsigned int	result;

	i = 0;
	result = 0;
	while (str[i] && !(ft_isdigit(str[i])))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

void				put_result(int y, int x)
{
	char *xx;
	char *yy;

	ft_putstr(xx = ft_itoa(y));
	write(1, " ", 1);
	ft_putstr(yy = ft_itoa(x));
	write(1, "\n", 1);
}