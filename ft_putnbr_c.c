/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:16:41 by nhirzel           #+#    #+#             */
/*   Updated: 2021/11/11 15:43:40 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_c(char c, int *compt)
{
	write(1, &c, 1);
	(*compt)++;
}

void	ft_putstr_c(char *s, int *compt)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		*compt = (*compt) + 6;
		return ;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		(*compt)++;
	}
}

void	long_putnbr(unsigned int n, int *compt)
{
	if (n < 0)
	{
		ft_putchar_c('-', compt);
		ft_putnbr_c(-n, compt);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_c(n / 10, compt);
		}
		ft_putchar_c(48 + n % 10, compt);
	}
}

void	ft_putnbr_c(int n, int *compt)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*compt = (*compt) + 11;
	}
	else if (n < 0)
	{
		ft_putchar_c('-', compt);
		ft_putnbr_c(-n, compt);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_c(n / 10, compt);
		}
		ft_putchar_c(48 + n % 10, compt);
	}
}
