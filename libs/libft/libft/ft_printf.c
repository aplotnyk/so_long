/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:48:05 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/07/11 20:12:47 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_paramcheck(va_list args, char c)
{
	int	s;

	s = 0;
	if (c == 'c')
		s = ft_putchar(va_arg(args, int));
	else if (c == 's')
		s = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		s = ft_putptr(va_arg(args, uintptr_t));
	else if (c == 'i' || c == 'd')
		s = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		s = ft_putunsint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		s = ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		s = ft_putchar('%');
	return (s);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		size;
	int		i;

	size = 0;
	i = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			size += ft_paramcheck(args, s[i + 1]);
			i++;
		}
		else
			size += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (size);
}
