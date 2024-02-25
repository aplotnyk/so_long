/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:33:14 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/26 15:18:09 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	int		i;
	int		n;
	char	*str2;
	char	*start;

	i = 0;
	n = ft_strlen((char *)str1);
	str2 = malloc(sizeof(char) * (n + 1));
	if (!str2)
		return (NULL);
	start = str2;
	while (i < n)
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (start);
}
