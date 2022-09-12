/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliangso <earth78203@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:28:19 by tliangso          #+#    #+#             */
/*   Updated: 2022/09/12 22:53:54 by tliangso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PARAMETERS
// lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// del: The address of the function used to delete
// the content of a node if needed.

// DESCRIPTION
// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

// RETURN VALUE
// The new list.
// NULL if the allocation fails.

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*new_tmp;
	t_list	*new_node;

	if (lst == NULL)
		return (NULL);
	new_node = ft_lstnew(ft_strdup((*f)(lst->content)));
	if (new_node == NULL)
		return (NULL);
	new_tmp = new_node;
	tmp = lst;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_node->next = ft_lstnew(ft_strdup((*f)(lst->content)));
		if (new_node->next == NULL)
		{
			ft_lstclear(&new_tmp, del);
			return (NULL);
		}
		new_node = new_node->next;
	}
	ft_lstclear(&tmp, del);
	return (new_tmp);
}
