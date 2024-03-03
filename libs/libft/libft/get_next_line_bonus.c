/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:09:49 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/02/29 14:07:54 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// char	*detect_line(int fd, char *bkm)
// {
// 	char	*buf;
// 	int		nbytes_read;

// 	nbytes_read = 1;
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	while (nbytes_read > 0 && !ft_strchr(bkm, '\n'))
// 	{
// 		nbytes_read = read(fd, buf, BUFFER_SIZE);
// 		if (nbytes_read == 0)
// 			break ;
// 		if (nbytes_read == -1)
// 		{
// 			free(buf);
// 			return (NULL);
// 		}
// 		buf[nbytes_read] = '\0';
// 		bkm = ft_strjoin(bkm, buf);
// 	}
// 	free(buf);
// 	return (bkm);
// }

// char	*extract_line(char *bkm)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	if (!*bkm)
// 		return (NULL);
// 	while (bkm[i] && bkm[i] != '\n')
// 		i++;
// 	line = malloc(sizeof(char) * (i + 2));
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (bkm[i] && bkm[i] != '\n')
// 	{
// 		line[i] = bkm[i];
// 		i++;
// 	}
// 	if (bkm[i] == '\n')
// 	{
// 		line[i] = bkm[i];
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// char	*next_line(char *bkm)
// {
// 	char	*next_line;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (bkm[i] && bkm[i] != '\n')
// 		i++;
// 	if (!bkm[i])
// 	{
// 		free(bkm);
// 		return (NULL);
// 	}
// 	next_line = malloc (sizeof(char) * (ft_strlen(bkm) + 1 - i));
// 	if (!next_line)
// 		return (NULL);
// 	i++;
// 	while (bkm[i])
// 		next_line[j++] = bkm[i++];
// 	next_line[j] = '\0';
// 	free(bkm);
// 	return (next_line);
// }

// char	*get_next_line(int fd)
// {
// 	static char		*bookmark[1024];
// 	char			*line;

// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (NULL);
// 	bookmark[fd] = detect_line(fd, bookmark[fd]);
// 	if (!bookmark[fd])
// 		return (NULL);
// 	line = extract_line(bookmark[fd]);
// 	bookmark[fd] = next_line(bookmark[fd]);
// 	return (line);
// }

// char	*detect_line(int fd, char *bkm)
// {
// 	char	*buf;
// 	int		nbytes_read;

// 	nbytes_read = 1;
// 	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	while (nbytes_read > 0 && !ft_strchr(bkm, '\n'))
// 	{
// 		nbytes_read = read(fd, buf, BUFFER_SIZE);
// 		if (nbytes_read == 0)
// 			break ;
// 		if (nbytes_read == -1)
// 		{
// 			free(buf);
// 			return (NULL);
// 		}
// 		buf[nbytes_read] = '\0';
// 		bkm = ft_strjoin(bkm, buf);
// 	}
// 	free(buf);
// 	return (bkm);
// }

char	*detect_line(int fd, char *bkm)
{
	char	*buf;
	char	*tmp;
	int		nbytes_read;

	nbytes_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// buf = (char *) ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	while (nbytes_read != 0 && !ft_strchr(bkm, '\n'))
	{
		nbytes_read = read(fd, buf, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[nbytes_read] = '\0';
		tmp = bkm;
		if (tmp == NULL)
			tmp = (char *) ft_calloc(1, sizeof(char));
		bkm = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (bkm);
}

char	*extract_line(char *bkm)
{
	char	*line;
	int		i;

	i = 0;
	if (!*bkm)
		return (NULL);
	while (bkm[i] && bkm[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (bkm[i] && bkm[i] != '\n')
	{
		line[i] = bkm[i];
		i++;
	}
	if (bkm[i] == '\n')
	{
		line[i] = bkm[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*next_line(char *bkm)
{
	char	*next_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (bkm[i] && bkm[i] != '\n')
		i++;
	if (!bkm[i])
	{
		free(bkm);
		return (NULL);
	}
	next_line = malloc (sizeof(char) * (ft_strlen(bkm) + 1 - i));
	if (!next_line)
		return (NULL);
	i++;
	while (bkm[i])
		next_line[j++] = bkm[i++];
	next_line[j] = '\0';
	free(bkm);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char		*bookmark[1024];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	bookmark[fd] = detect_line(fd, bookmark[fd]);
	if (!bookmark[fd])
		return (NULL);
	line = extract_line(bookmark[fd]);
	bookmark[fd] = next_line(bookmark[fd]);
	return (line);
}
