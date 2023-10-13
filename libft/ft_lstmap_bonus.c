/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:01:04 by escastel          #+#    #+#             */
/*   Updated: 2023/05/05 17:55:55 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cpy;

	if (!lst || !del || !f)
		return (0);
	new_lst = 0;
	while (lst)
	{
		cpy = ft_lstnew(f(lst->content));
		if (!cpy)
		{
			ft_lstclear(&cpy, del);
			return (0);
		}
		else
		{
			ft_lstadd_back(&new_lst, cpy);
			lst = lst->next;
		}
	}
	return (new_lst);
}
