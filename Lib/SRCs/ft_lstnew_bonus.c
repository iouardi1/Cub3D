/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouardi <iouardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:53:35 by iouardi           #+#    #+#             */
/*   Updated: 2023/01/08 03:53:40 by iouardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

t_list	*ft_lstnew(void	*content)
{
	t_list	*final;

	final = (t_list *)malloc(sizeof(t_list));
	if (final == NULL)
		return (NULL);
	final->content = content;
	final->next = NULL;
	return (final);
}
