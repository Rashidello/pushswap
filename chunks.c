/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 22:01:18 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/16 22:01:18 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_node	**a, t_node	**b, int size)
{
	int	chunk;
	int	i;

	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	i = 0;
	while (*a)
	{
		if ((*a)-> index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)-> index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	push_to_a(t_node **a, t_node **b)
{
	int	max;

	while (*b)
	{
		max = max_index_in_b(*b);
		if (get_pos(*b, max) <= stack_size(*b) / 2)
			while ((*b)-> index != max)
				rb(b);
		else
			while ((*b)-> index != max)
				rrb(b);
		pa(a, b);
	}
}

void	chunks(t_node	**a, t_node	**b, int size)
{
	if (is_sorted(*a))
		return ;
	push_to_b(a, b, size);
	push_to_a(a, b);
}
