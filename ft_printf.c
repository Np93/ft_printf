/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 22:21:33 by nhirzel           #+#    #+#             */
/*   Updated: 2021/11/11 19:02:18 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_trie(const char *str, va_list args, int i, int *compt)
{
	if (str[i] == 'c')
		ft_putchar_c(va_arg(args, int), compt);
	if (str[i] == 's')
		ft_putstr_c(va_arg(args, char *), compt);
	if (str[i] == 'i' || str[i] == 'd')
		ft_putnbr_c(va_arg(args, int), compt);
	if (str[i] == '%')
		ft_putchar_c('%', compt);
	if (str[i] == 'u')
		long_putnbr(va_arg(args, unsigned int), compt);
	if (str[i] == 'x')
		ft_ito(va_arg(args, unsigned int), compt, 'x');
	if (str[i] == 'X')
		ft_ito(va_arg(args, unsigned int), compt, 'X');
	if (str[i] == 'p')
	{
		ft_putstr_c("0x", compt);
		ft_ito(va_arg(args, unsigned long), compt, 'x');
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		compt;

	if (str == NULL)
		return (0);
	compt = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			ft_putchar_c(str[i], &compt);
		if (str[i] == '%')
		{
			i++;
			ft_trie(str, args, i, &compt);
		}
		i++;
	}
	va_end(args);
	return (compt);
}
