/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:27:09 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/05 18:27:09 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_map(t_node *a, int size)
{
	t_node	*tmp;
	t_node	*min;
	int		i;

	i = 0;
	while (i < size)
	{
		tmp = a;
		min = NULL;
		while (tmp)
		{
			if (tmp -> index == -1 && (min == NULL
					|| tmp -> value < min -> value))
				min = tmp;
			tmp = tmp -> next;
		}
		if (min)
			min -> index = i;
		i++;
	}
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!str || str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoll(str) > 2147483647 || ft_atoll(str) < -2147483648)
		return (0);
	return (1);
}

int	is_duplicate(t_node *a, int value)
{
	while (a)
	{
		if (a -> value == value)
			return (1);
		a = a ->next;
	}
	return (0);
}

void	parse(t_node **stack_a, int *size, char *str)
{
	char	**tokens;
	int		j;

	tokens = ft_split(str, ' ');
	if (!tokens || !tokens[0])
		error (stack_a, tokens);
	j = 0;
	while (tokens[j])
		j++;
	j--;
	while (j >= 0)
	{
		if (!is_valid(tokens[j]))
			error(stack_a, tokens);
		if (is_duplicate(*stack_a, (int)ft_atoll(tokens[j])))
			error(stack_a, tokens);
		push_front(stack_a, ft_atoll(tokens[j]));
		(*size)++;
		free(tokens[j]);
		j--;
	}
	free(tokens);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;
	int		i;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	i = argc - 1;
	while (i >= 1)
	{
		parse(&stack_a, &size, argv[i]);
		i--;
	}
	index_map(stack_a, size);
	chunks(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}
