/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escastel <escastel@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:20:40 by escastel          #+#    #+#             */
/*   Updated: 2023/05/05 15:38:05 by escastel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*clear;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		clear = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = clear;
	}
	*lst = 0;
	return ;
}
