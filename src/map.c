/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:22:10 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/01 20:55:33 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**fill_map_array(int fd)
{
	char	*new_line;
	char	*prev_lines;
	char	*map_in_str;
	char	**map_array;

	new_line = get_next_line(fd);
	if (!new_line)
		return (NULL);
	prev_lines = NULL;
	map_in_str = ft_strjoin("", new_line);
	free(new_line);
	while (true)
	{
		new_line = get_next_line(fd);
		if (!new_line)
			break ;
		prev_lines = map_in_str;
		map_in_str = ft_strjoin(prev_lines, new_line);
		free(prev_lines);
		free(new_line);
	}
	map_array = ft_split(map_in_str, '\n');
	free(map_in_str);
	return (map_array);
}

char	**load_map_content(char *mapname)
{
	char	*map_path;
	char	**map_array;
	int		fd;

	map_path = ft_strjoin("./map/", mapname);
	fd = open(map_path, O_RDONLY, 0444);
	free(map_path);
	if (fd < 0)
		error_msg("Error: Map not found in so_long/map.\n");
	map_array = fill_map_array(fd);
	if (map_array == NULL)
		error_msg("Error: Empty map file.\n");
	return (map_array);
}

void	extension_check(char *mapname)
{
	char	*ext;
	size_t	i;

	ext = ".ber";
	i = 0;
	while (i <= 3)
	{
		if (ext[ft_strlen(ext) - i] == mapname[ft_strlen(mapname) - i])
			i++;
		else
			error_msg("Error: expected map with *.ber extension\n");
	}
	ft_putstr_fd("Map extension is correct\n", 1);
}

t_map	*read_map(char *mapname)
{
	t_map	*map;
	char	**map_content;

	extension_check(mapname);
	map = (t_map *) malloc(sizeof(t_map));
	map_content = load_map_content(mapname);
	map_is_rectangular(map_content, map);
	map_walls_around(map_content);
	map_valid_chars_check(map_content, map);
	map->mapdata = map_content;
	map_valid_path_check(map);
	map->exit_open = 0;
	return (map);
}
