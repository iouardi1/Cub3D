/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msouiyeh <msouiyeh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:52:39 by msouiyeh          #+#    #+#             */
/*   Updated: 2022/09/07 21:51:58 by msouiyeh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_lib.h"

void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
