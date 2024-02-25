/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:14:06 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/07/12 16:19:00 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(int i)
{
	int		size;
	char	*s;

	s = ft_itoa(i);
	size = ft_putstr(s);
	free(s);
	return (size);
}
