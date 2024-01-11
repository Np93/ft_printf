/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:20:38 by nhirzel           #+#    #+#             */
/*   Updated: 2021/11/11 15:56:26 by nhirzel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_c(char c, int *compt);
void	ft_putnbr_c(int n, int *compt);
void	ft_putstr_c(char *s, int *compt);
void	long_putnbr(unsigned int n, int *compt);
void	ft_ito(unsigned long n, int *compt, char c);

#endif
