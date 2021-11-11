/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:44:52 by nhirzel           #+#    #+#             */
/*   Updated: 2021/11/11 15:56:51 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conte(unsigned long n)
{
	unsigned long	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i = 2;
	}
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_ito(unsigned long n, int *compt, char c)
{
	char			*s;
	unsigned long	i;

	if (n < 0)
		return (ft_ito(INT_MAX - (n * -1), compt, c));
	i = conte(n);
	s = malloc(i + 1 * sizeof(char));
	if (!s)
		return ;
	if (n == 0)
		s[0] = '0';
	s[i--] = '\0';
	while (n > 0)
	{
		if (c == 'x')
			s[i--] = "0123456789abcdef"[n % 16];
		else
			s[i--] = "0123456789ABCDEF"[n % 16];
		n = n / 16;
	}
	ft_putstr_c(s, compt);
	free(s);
}
