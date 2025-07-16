/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribolzi <pribolzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:06:38 by pribolzi          #+#    #+#             */
/*   Updated: 2025/01/10 15:00:15 by pribolzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*suite;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		suite = temp->next;
		del(temp->content);
		free (temp);
		temp = suite;
	}
	*lst = NULL;
}
