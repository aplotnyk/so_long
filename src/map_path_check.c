/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:58:14 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/02/25 21:47:26 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	path_check(int y, int x, char **maparr, t_map_check_data *check_values)
{
	if (maparr[y][x] == '1' || check_values->visited[y][x])
		return ;
	else if (maparr[y][x] == 'E')
		check_values->exit_found = 1;
	else if (maparr[y][x] == 'C')
		check_values->collect_found += 1;
	check_values->visited[y][x] = 1;
	path_check(y - 1, x, maparr, check_values);
	path_check(y, x - 1, maparr, check_values);
	path_check(y + 1, x, maparr, check_values);
	path_check(y, x + 1, maparr, check_values);
}

void	free_map_visited(int ***map, int curr_row)
{
	int	i;

	i = 0;
	while (i < curr_row)
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}

int	**init_map_visited(t_map *map)
{
	int	**map_visited;
	int	row;
	int	col;

	map_visited = malloc(sizeof(int *) * map->row_count);
	if (!map_visited)
		return (NULL);
	row = 0;
	while (row < map->row_count)
	{
		map_visited[row] = malloc(sizeof(int) * map->col_count);
		if (!map_visited[row])
			free_map_visited(&map_visited, row);
		col = 0;
		while (col < map->col_count)
		{
			map_visited[row][col] = 0;
			col++;
		}
		row++;
	}
	return (map_visited);
}

t_map_check_data	get_check_data(t_map *map)
{
	t_map_check_data	map_check_data;

	map_check_data.visited = init_map_visited(map);
	map_check_data.collect_found = 0;
	map_check_data.exit_found = 0;
	return (map_check_data);
}

void	map_valid_path_check(t_map	*map)
{
	t_map_check_data	map_check_data;

	map_check_data = get_check_data(map);
	path_check(map->player_y, map->player_x, map->mapdata, &map_check_data);
	free_map_visited(&(map_check_data.visited), map->row_count);
	if (!map_check_data.exit_found)
	{
		free_map(map->mapdata);
		error_msg("Error: Cannot reach the exit\n");
	}
	if (map_check_data.collect_found != (*map).total_score)
	{
		free_map(map->mapdata);
		error_msg("Error: Cannot reach all collectables\n");
	}
	ft_putstr_fd("Valid path check done.\n", 1);
}
