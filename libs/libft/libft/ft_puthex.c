/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:43:29 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/07/11 20:23:15 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexsize(unsigned int ui)
{
	int	len;

	len = 0;
	while (ui != 0)
	{
		ui /= 16;
		len++;
	}
	return (len);
}

static char	*ft_itoahex(unsigned int ui, int xcase)
{
	int		len;
	char	*ptr;
	int		i;

	len = ft_hexsize(ui);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (ui)
	{
		i = ui % 16;
		if (i < 10)
			ptr[len - 1] = i + '0';
		else
			ptr[len - 1] = i + xcase;
		ui /= 16;
		len--;
	}
	return (ptr);
}

int	ft_puthex(unsigned int ui, char xcase)
{
	int		size;
	char	*str;

	if (!ui)
	{
		write(1, "0", 1);
		return (1);
	}
	if (xcase == 'X')
		xcase = 55;
	else
		xcase = 87;
	str = ft_itoahex(ui, xcase);
	size = ft_putstr(str);
	free(str);
	return (size);
}
