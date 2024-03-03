/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:48:03 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/03 21:57:20 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	error_arg(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: Please enter 2 arguments.\n", 2);
		exit(1);
	}
}

void	error_msg(char	*str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error(void)
{
	ft_putstr_fd((char *) mlx_strerror(mlx_errno), 2);
	exit(EXIT_FAILURE);
}
