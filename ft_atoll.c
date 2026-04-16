/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarayano <rarayano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 03:34:02 by rarayano          #+#    #+#             */
/*   Updated: 2026/04/17 02:13:49 by rarayano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(const	char *str)
{
	int			i;
	long long	nu;
	int			ng;

	i = 0;
	nu = 0;
	ng = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ng++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nu = nu * 10 + (str[i] - '0');
		i++;
	}
	if (ng == 1)
		return (nu = -nu);
	return (nu);
}
