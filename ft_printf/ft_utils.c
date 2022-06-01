/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <yobenali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:10:58 by yobenali          #+#    #+#             */
/*   Updated: 2021/12/15 16:53:29 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

void	ft_putnbr_base(unsigned long nbr, char *base, int *count)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, base, count);
		ft_putnbr_base(nbr % i, base, count);
	}
	else
	{
		write(1, base + nbr, 1);
		(*count)++;
	}
}

void	ft_putnbr_base2(unsigned int nbr, char *base, int *count)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, base, count);
		ft_putnbr_base(nbr % i, base, count);
	}
	else
	{
		write(1, base + nbr, 1);
		(*count)++;
	}
}

void	ft_putnbr(int nb, int *count)
{
	unsigned int	n;

	if (nb < 0)
	{
		*count += ft_putchar('-');
		nb *= -1;
	}
	n = nb;
	if (n >= 10)
		ft_putnbr(n / 10, count);
	*count += ft_putchar(n % 10 + '0');
}
