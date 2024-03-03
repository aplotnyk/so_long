/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 04:27:33 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/02 17:54:52 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map_is_rectangular(char	**map_content, t_map *map)
{
	size_t	rows_count;
	size_t	first_row_len;
	size_t	curr_row_len;

	rows_count = 0;
	first_row_len = ft_strlen(map_content[rows_count]);
	while (map_content[++rows_count] != NULL)
	{
		curr_row_len = ft_strlen(map_content[rows_count]);
		if (curr_row_len != first_row_len)
			error_msg("Error: Map rows not of the same length\n");
	}
	if (rows_count < 3)
		exit (1);
	map->row_count = rows_count;
	map->col_count = first_row_len;
	ft_putstr_fd("Map is rectangular, great!\n", 1);
}

void	map_walls_around(char **map_content)
{
	size_t	row_len;
	size_t	rows_count;

	rows_count = 0;
	row_len = ft_strlen(map_content[rows_count]);
	while (map_content[rows_count][row_len])
	{
		if (map_content[rows_count][row_len] != '1')
			error_msg("Error: Map not surrounded by walls\n");
		row_len--;
	}
	while (map_content[++rows_count + 2] != NULL)
	{
		if (map_content[rows_count][0] != '1'
			|| map_content[rows_count][row_len - 1] != '1')
			error_msg("Error: Map not surrounded by walls\n");
	}
	while (map_content[rows_count][row_len])
	{
		if (map_content[rows_count][row_len] != '1')
			error_msg("Error: Map not surrounded by walls\n");
		row_len--;
	}
	ft_putstr_fd("Map surrounded by walls.\n", 1);
}

void	valid_char_scan(char map_char)
{
	if (map_char != '0' && map_char != '1'
		&& map_char != 'P' && map_char != 'E'
		&& map_char != 'C' && map_char != 'A')
		error_msg("Error: Map contains invalid charaters\n");
}

int	player_pos_check(char map_char, int x, int y, t_map *map)
{
	if (map_char == 'P')
	{
		map->player_x = x;
		map->player_y = y;
		return (1);
	}
	return (0);
}

void	map_valid_chars_check(char **map_content, t_map *map)
{
	int		x;
	int		y;
	int		players;
	int		exits;
	int		collects;

	y = 0;
	players = 0;
	exits = 0;
	collects = 0;
	while (map_content[++y + 1] != NULL)
	{
		x = 0;
		while (map_content[y][++x])
		{
			valid_char_scan(map_content[y][x]);
			players += player_pos_check(map_content[y][x], x, y, map);
			if (map_content[y][x] == 'E')
				exits++;
			else if (map_content[y][x] == 'C')
				collects++;
		}
	}
	valid_chars_check_res(players, exits, collects, map);
}
