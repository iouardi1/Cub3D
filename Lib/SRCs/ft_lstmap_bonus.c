/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:37:58 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	tmp = head;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
/*void	*mod(void *ptr)
{
	((char *)ptr)[0] += 1;

	return (ptr);
}
void	dell(void *t)
{
	(void)t;
}
#include <stdio.h>
int	main(void)
{
	t_list	*p;
	void	*(*f)(void *);
	t_list	*con;

	f = &mod;
	p = ft_lstnew(ft_strdup("well"));
	p->next = ft_lstnew(ft_strdup("well2"));
	p->next->next = ft_lstnew(ft_strdup("well3"));
	printf("%s\n%s\n%s\n", (char *)(p->content), (char *)((p->next)->content), 
			(char *)((p->next->next)->content));
	con = ft_lstmap(p, f, &dell);
	printf("%s\n%s\n%s\n", (char *)(con->content), (char *)((con->next)->content), 
			(char *)((con->next->next)->content));

}*/
