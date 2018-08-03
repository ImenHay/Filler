/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <imhaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 01:41:56 by imhaimou          #+#    #+#             */
/*   Updated: 2018/03/24 12:44:36 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_hex(int nb)
{
	int		i;
	char	*s;

	if (!((s = (char*)malloc(sizeof(char) * 17))))
		return ;
	s = "0123456789abcdef";
	i = 0;
	if (nb >= 16)
	{
		print_hex(nb / 16);
		i = nb % 16;
		ft_putchar(s[i]);
	}
	else
		ft_putchar(s[nb]);
}
