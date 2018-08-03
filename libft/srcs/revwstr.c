/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revwstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <imhaimou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 19:15:34 by exam              #+#    #+#             */
/*   Updated: 2018/03/24 12:44:04 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	revwstr(char *s)
{
	int	i;
	int	start;

	i = 0;
	while (s[i] && ft_space(s[i]))
		i++;
	if (!s[i])
		return ;
	start = i;
	while (s[i] && !ft_space(s[i]))
		i++;
	revwstr(&s[i]);
	write(1, &s[start], i - start);
	if (start > 0)
		write(1, " ", 1);
}
