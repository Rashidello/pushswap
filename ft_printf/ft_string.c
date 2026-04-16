/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 21:34:44 by rarayano          #+#    #+#             */
/*   Updated: 2025/12/31 21:34:44 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *str)
{
	int	i;
	int	proverka;

	proverka = 0;
	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		proverka = write(1, &str[i], 1);
		if (proverka == -1)
			return (-1);
		i++;
	}
	return (i);
}
