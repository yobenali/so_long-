/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <yobenali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:53:19 by yobenali          #+#    #+#             */
/*   Updated: 2021/12/15 16:53:06 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	print_type(va_list arg, char c, int *count)
{
	if (c == 'c')
		*count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		*count += ft_putstr(va_arg(arg, char *));
	else if (c == '%')
		*count += ft_putchar('%');
	else if (c == 'p')
	{
		*count += ft_putstr("0x");
		ft_putnbr_base(va_arg(arg, unsigned long), "0123456789abcdef", count);
	}
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), count);
	else if (c == 'u')
		ft_putnbr_base2(va_arg(arg, unsigned int), "0123456789", count);
	else if (c == 'x')
		ft_putnbr_base2(va_arg(arg, unsigned int), "0123456789abcdef", count);
	else if (c == 'X')
		ft_putnbr_base2(va_arg(arg, unsigned int), "0123456789ABCDEF", count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_type(arg, str[i + 1], &count);
			i += 2;
		}
		else
		{
			count += ft_putchar(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (count);
}
