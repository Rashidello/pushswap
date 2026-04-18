/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:00:48 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/16 22:00:48 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> index = -1;
	new -> next = NULL;
	return (new);
}

void	push_front(t_node **stack, int value)
{
	t_node	*new;

	new = new_node(value);
	new -> next = *stack;
	*stack = new;
}

int	stack_size(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack -> next;
	}
	return (i);
}

int	get_pos(t_node *b, int index)
{
	int	i;

	i = 0;
	while (b)
	{
		if (b -> index == index)
			return (i);
		i++;
		b = b -> next;
	}
	return (0);
}

int	get_min_index_in_a(t_node *a)
{
	int	min;

	if (!a)
		return (-1);
	min = a->index;
	while (a)
	{
		if (a->index < min)
			min = a->index;
		a = a->next;
	}
	return (min);
}
