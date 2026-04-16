/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 21:34:41 by rarayano          #+#    #+#             */
/*   Updated: 2025/12/31 21:34:41 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

ssize_t	ag(va_list *args, char print_out)
{
	if (print_out == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (print_out == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (print_out == 'x' || print_out == 'X')
		return (ft_hex(va_arg(*args, unsigned int), print_out));
	if (print_out == 'p')
		return (ft_ptr(va_arg(*args, unsigned long long)));
	if (print_out == 'i' || print_out == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (print_out == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (print_out == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *print_out, ...)
{
	int		i;
	int		len;
	int		proverka;
	va_list	args;

	len = 0;
	i = 0;
	va_start(args, print_out);
	while (print_out[i])
	{
		if (print_out[i] == '%')
		{
			if (print_out[i + 1] == '\0')
				return (va_end(args), -1);
			i++;
			proverka = ag(&args, print_out[i]);
		}
		else
			proverka = ft_putchar(print_out[i]);
		if (proverka == -1)
			return (va_end(args), -1);
		len += proverka;
		i++;
	}
	return (va_end(args), len);
}
