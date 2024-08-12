/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:50:10 by tkirmizi          #+#    #+#             */
/*   Updated: 2024/08/11 14:37:01 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_hexa_low(unsigned int num);
int		ft_hexa_up(unsigned int num);
char	*ft_itoa(int n);
int		ft_putnbr(int num);
int		ft_u_putnbr(unsigned int num);
int		ft_cases(va_list ap, const char *str);
int		ft_printf_adr(void *ptr);

#endif