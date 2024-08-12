/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:50 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/04/10 21:00:22 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_up(unsigned int num)
{
	char	*base;
	int		count;
	int		check;

	count = 0;
	check = 0;
	base = "0123456789ABCDEF";
	if (num > 15)
	{
		check += ft_hexa_up(num / 16);
		if (check == -1)
			return (-1);
		check += ft_hexa_up(num % 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	else
	{
		if (ft_putchar(base[num]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_hexa_low(unsigned int num)
{
	char	*base;
	int		count;
	int		check;

	count = 0;
	check = 0;
	base = "0123456789abcdef";
	if (num > 15)
	{
		check += ft_hexa_low(num / 16);
		if (check == -1)
			return (-1);
		check += ft_hexa_low(num % 16);
		if (check == -1)
			return (-1);
		count += check;
	}
	else
	{
		if (ft_putchar(base[num]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
