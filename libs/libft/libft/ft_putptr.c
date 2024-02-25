/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:17:55 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/07/11 20:20:20 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexsize(uintptr_t u)
{
	int	len;

	len = 0;
	while (u != 0)
	{
		u /= 16;
		len++;
	}
	return (len);
}

static char	*itohex(uintptr_t u)
{
	char	*ptr;
	int		len;
	int		i;

	len = ft_hexsize(u);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (u)
	{
		i = u % 16;
		if (i < 10)
			ptr[len - 1] = i + '0';
		else
			ptr[len - 1] = i + 87;
		u /= 16;
		len--;
	}
	return (ptr);
}

int	ft_putptr(uintptr_t u)
{
	char	*s;
	int		len;

	len = 0;
	s = NULL;
	if (!u)
	{
		s = "(nil)";
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	len += write(1, "0x", 2);
	s = itohex(u);
	len += ft_putstr(s);
	free(s);
	return (len);
}
