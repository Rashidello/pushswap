/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 02:20:16 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/17 02:20:16 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

long	ft_atoll(const char *str);
char	**ft_split(char	const *s, char c);

int		ft_printf(const char *print_out, ...);
ssize_t	ft_putnbr(int nbr);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putunbr(unsigned int nbr);
ssize_t	ft_hex(unsigned long long nbr, char cors);
ssize_t	ft_ptr(unsigned long long nbr);

int		max_index_in_b(t_node *b);
int		is_sorted(t_node *a);
void	free_stack(t_node **stack);
void	error(void);
int		ft_isdigit(char c);

void	ra(t_node **a);
void	rb(t_node **b);
void	rrb(t_node **b);
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	sa(t_node **a);
void	rra(t_node **a);

void	push_to_b(t_node **a, t_node **b, int size);
void	push_to_a(t_node **a, t_node **b);
void	min_three(t_node **a);
void	min_five(t_node **a, t_node **b, int size);
void	chunks(t_node **a, t_node **b, int size);

int		is_valid(char *str);
int		is_duplicate(t_node *a, int value);
void	parse(t_node **stack_a, int *size, char *str);
int		main(int argc, char **argv);

t_node	*new_node(int value);
void	push_front(t_node **stack, int value);
int		stack_size(t_node *stack);
int		get_pos(t_node *b, int index);
int		get_min_index_in_a(t_node *a);

#endif