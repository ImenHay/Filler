/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:13:58 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/14 20:44:33 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*k;

	k = (t_list*)malloc(sizeof(t_list));
	if (!k)
		return (NULL);
	if (content == NULL)
	{
		k->content = NULL;
		k->content_size = 0;
	}
	else
	{
		k->content = malloc(content_size);
		if (!k->content)
			return (NULL);
		ft_memcpy((k->content), content, content_size);
		k->content_size = content_size;
	}
	k->next = (NULL);
	return (k);
}
