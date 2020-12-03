/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jraty <jraty@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 14:17:33 by jraty             #+#    #+#             */
/*   Updated: 2020/09/16 15:06:25 by jraty            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*head;
	t_list		*temp;

	if (!lst)
		return (NULL);
	if (!(head = f(lst)))
		return (NULL);
	temp = head;
	while ((lst = lst->next))
	{
		temp->next = f(lst);
		temp = temp->next;
		if (!temp)
		{
			ft_lstfree(&head);
			return (NULL);
		}
	}
	temp->next = NULL;
	return (head);
}
