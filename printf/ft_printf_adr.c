/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_adr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:15:02 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/04/10 17:32:33 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_adr_writer(unsigned long num, int count)
{
	char	*hexa_num;

	hexa_num = "0123456789abcdef";
	if (num != 0)
	{
		count = ft_adr_writer(num / 16, count);
		count += ft_putchar(hexa_num[num % 16]);
	}
	return (count);
}

int	ft_printf_adr(void *ptr)
{
	unsigned long	num;
	int				count;

	count = 0;
	num = (unsigned long)ptr;
	if ((write(1, "0x", 2)) == -1)
		return (-1);
	if (num == 0)
	{
		count = write(1, "0", 1);
		if (count == -1)
			return (-1);
		return (3);
	}
	count = ft_adr_writer(num, count);
	return (count + 2);
}
