/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 13:27:57 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/18 13:27:57 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*tmp;

	if (!*a || !(*a)-> next)
		return ;
	tmp = (*a)-> next;
	(*a)-> next = tmp-> next;
	tmp -> next = *a;
	*a = tmp;
	ft_printf("sa\n");
}

void	rra(t_node **a)
{
	t_node	*tmp;
	t_node	*prev;

	if (!*a || !(*a)-> next)
		return ;
	prev = *a;
	while (prev -> next-> next)
		prev = prev -> next;
	tmp = prev -> next;
	prev -> next = NULL;
	tmp -> next = *a;
	*a = tmp;
	ft_printf("rra\n");
}
