/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:59:34 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/06 16:30:22 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_lenunsign(unsigned int ui)
{
	int	len;

	len = 0;
	while (ui)
	{
		len++;
		ui /= 10;
	}
	return (len);
}

static char	*itoaunsign(unsigned int ui)
{
	int		size;
	char	*ptr;

	size = ft_lenunsign(ui);
	ptr = malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ptr[size] = '\0';
	while (ui)
	{
		ptr[size - 1] = ui % 10 + '0';
		ui /= 10;
		size--;
	}
	return (ptr);
}

int	ft_putunsint(unsigned int ui)
{
	int		size;
	char	*str;

	if (!ui)
	{
		write(1, "0", 1);
		return (1);
	}
	str = itoaunsign(ui);
	size = ft_putstr(str);
	free(str);
	return (size);
}
