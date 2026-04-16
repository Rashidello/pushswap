/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:00:52 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/16 22:00:52 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index_in_b(t_node *b)
{
	int	max;

	if (!b)
		return (-1);
	max = b -> index;
	b = b-> next;
	while (b)
	{
		if (b-> index > max)
			max = b -> index;
		b = b ->next;
	}
	return (max);
}

int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a -> next)
	{
		if (a -> index > a ->next->index)
			return (0);
		a = a -> next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)-> next;
		free(*stack);
		*stack = tmp;
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
