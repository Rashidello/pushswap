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
	int	pos;

	while (*b)
	{
		max = max_index_in_b(*b);
		pos = get_pos(*b, max);
		if (pos <= stack_size(*b) / 2)
			while ((*b)->index != max)
				rb(b);
		else
			while ((*b)->index != max)
				rrb(b);
		pa(a, b);
	}
}

void	min_three(t_node **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)-> index;
	mid = (*a)-> next-> index;
	bot = (*a)-> next -> next -> index;
	if (top > mid && top > bot)
		ra(a);
	else if (mid > top && mid > bot)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	min_five(t_node **a, t_node **b, int size)
{
	int	min_idx;
	int	pos;

	while (size > 3)
	{
		min_idx = get_min_index_in_a(*a);
		pos = get_pos(*a, min_idx);
		if (pos <= size / 2)
			while ((*a)->index != min_idx)
				ra(a);
		else
			while ((*a)->index != min_idx)
				rra(a);
		pb(a, b);
		size--;
	}
	min_three(a);
	while (*b)
		pa(a, b);
}

void	chunks(t_node **a, t_node **b, int size)
{
	if (is_sorted(*a))
		return ;
	else if (size == 2)
		sa(a);
	else if (size == 3)
		min_three(a);
	else if (size == 5 || size == 4)
		min_five(a, b, size);
	else
	{
		push_to_b(a, b, size);
		push_to_a(a, b);
	}
}
