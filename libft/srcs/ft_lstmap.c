/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:13:21 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/14 17:28:44 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *k;

	k = NULL;
	if (lst)
	{
		if (!(k = (t_list*)malloc(sizeof(lst))))
			return (NULL);
		k = f(lst);
		k->next = ft_lstmap(lst->next, f);
		return (k);
	}
	return (NULL);
}
