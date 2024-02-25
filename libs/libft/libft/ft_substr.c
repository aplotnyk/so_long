/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:59:50 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/19 20:16:30 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if ((size_t)start + len > ft_strlen(s))
		len = len - (size_t)start;
	if ((size_t)start > ft_strlen(s))
		len = 0;
	substr = (char *) malloc (len + 1);
	if (!substr)
		return (NULL);
	while (len > 0)
	{
		substr[i] = s[start];
		start++;
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}
