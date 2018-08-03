/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 23:42:36 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/11 20:19:38 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	i = ft_strlen((char*)s);
	new = (char*)malloc(sizeof(char) * i + 1);
	if (!new)
		return (NULL);
	ft_strcpy(new, s);
	return (new);
}
