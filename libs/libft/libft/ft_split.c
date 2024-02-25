/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:34:53 by aplotnyk          #+#    #+#             */
/*   Updated: 2023/02/22 20:33:23 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	validchar_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_addword(char const *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = wordlen(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (len > 0)
	{
		word[i] = *s;
		s++;
		i++;
		len--;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word;

	word = 0;
	if (s == 0)
		return (NULL);
	result = malloc(sizeof(char *) * (validchar_count(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			result[word++] = ft_addword(s, c);
			s++;
		}
		while (*s && *s != c)
			s++;
	}
	result[word] = NULL;
	return (result);
}
