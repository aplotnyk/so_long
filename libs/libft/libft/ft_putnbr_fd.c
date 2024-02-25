/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:30:12 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/20 15:50:55 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	temp;

	if (n < 0)
	{
		temp = -n;
		write(fd, "-", 1);
	}
	else
		temp = n;
	if (temp >= 10)
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putnbr_fd(temp % 10, fd);
	}
	if (temp < 10)
	{
		temp = temp + '0';
		write(fd, &temp, 1);
	}
}
