/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:59:00 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/04/10 21:01:27 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) > 0)
		return (1);
	return (-1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		count += write(1, &str[i++], 1);
		if (i != count)
			return (-1);
	}
	return (count);
}
