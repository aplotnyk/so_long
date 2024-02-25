/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:04 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/08 19:54:02 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	n;

	i = ft_strlen(str);
	n = 0;
	while (i >= n)
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
