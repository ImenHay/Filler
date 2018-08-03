/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imhaimou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 14:10:33 by imhaimou          #+#    #+#             */
/*   Updated: 2017/05/08 14:11:13 by imhaimou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*k;
	t_list	*tmp;

	k = *alst;
	while (k != NULL)
	{
		tmp = k->next;
		del(k, k->content_size);
		k = tmp;
	}
	*alst = (NULL);
}
