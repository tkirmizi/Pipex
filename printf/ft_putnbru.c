/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:40:19 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/04/10 21:00:52 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int num)
{
	char	*str;
	int		count;

	str = ft_itoa(num);
	if (!str)
		return (-1);
	count = ft_putstr(str);
	free(str);
	return (count);
}

int	ft_u_putnbr(unsigned int num)
{
	int	count;

	count = 0;
	if (num > 9)
	{
		count = ft_putnbr(num / 10);
		if (count == -1)
			return (-1);
		num = num % 10;
	}
	if (ft_putnbr(num) == -1)
		return (-1);
	count++;
	return (count);
}
