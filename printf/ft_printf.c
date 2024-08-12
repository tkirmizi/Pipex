/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:38:30 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/04/10 17:44:36 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		counter;
	int		check;

	counter = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check = ft_cases(ap, str);
		}
		else
			check = write(1, str, 1);
		if (check == -1)
			return (-1);
		counter += check;
		str++;
	}
	va_end(ap);
	return (counter);
}

int	ft_cases(va_list ap, const char *str)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (*str == 'd' || *str == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (*str == 'u')
		return (ft_u_putnbr(va_arg(ap, int)));
	else if (*str == 'x')
		return (ft_hexa_low(va_arg(ap, int)));
	else if (*str == 'X')
		return (ft_hexa_up(va_arg(ap, int)));
	else if (*str == 'p')
		return (ft_printf_adr(va_arg(ap, void *)));
	else if (*str == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}
