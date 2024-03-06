/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:28:18 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/06 16:28:50 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
searches for the first occurrence of the character c
in the string pointed to by the argument str.
returns a pointer to the first occurrence of the character c in the string str,
or NULL if the character is not found
*/

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if (!str)
		return (NULL);
	while (*str && *str != ch)
		str++;
	if (*str == ch)
		return ((char *)str);
	else
		return (NULL);
}
