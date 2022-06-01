/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobenali <yobenali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:20:52 by yobenali          #+#    #+#             */
/*   Updated: 2021/12/15 16:58:11 by yobenali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	print_type(va_list arg, char c, int *count);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int nb, int *count);
void	ft_putnbr_base(unsigned long nbr, char *base, int *count);
void	ft_putnbr_base2(unsigned int nbr, char *base, int *count);

#endif
