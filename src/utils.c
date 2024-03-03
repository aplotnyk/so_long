/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:02:31 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/03 21:57:39 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	free_map(char **map)
{
	size_t	i;

	i = 0;
	while (*(map + i))
	{
		free(*(map + i));
		i++;
	}
	free(map);
	return (1);
}

int	free_imgs(t_game *game)
{
	mlx_delete_image(game->mlx, game->all_imgs->collect_img);
	mlx_delete_image(game->mlx, game->all_imgs->enemy_img);
	mlx_delete_image(game->mlx, game->all_imgs->e_closed_img);
	mlx_delete_image(game->mlx, game->all_imgs->e_open_img);
	mlx_delete_image(game->mlx, game->all_imgs->path_img);
	mlx_delete_image(game->mlx, game->all_imgs->player_img);
	mlx_delete_image(game->mlx, game->all_imgs->wall_img);
	return (1);
}

void	valid_chars_check_res(int p, int e, int c, t_map *map)
{
	if (p != 1 || e < 1)
		error_msg("Error: Player is not unique or no exits in map\n");
	map->total_score = c;
	ft_putstr_fd("Map contains correct chars.\n", 1);
}
