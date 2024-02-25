/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:15:54 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/02/26 00:13:49 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	enemy_exit(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map->mapdata);
	free(game->moves_str);
	free(game->score_s);
	ft_putstr_fd("You've been hunted by forest monster (°Ω°) \n", 1);
	exit(0);
}

void	final_exit(t_game *game)
{
	game->moves_c += 1;
	ft_printf("Mush moves: %d\n", game->moves_c);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map->mapdata);
	free(game->moves_str);
	free(game->score_s);
	ft_putstr_fd("The magic exit discovered, quest completed! ≽^• ⩊ •^≼ \n", 1);
	exit(0);
}
