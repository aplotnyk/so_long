/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:15:54 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/01 20:28:24 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	esc_pressed_termination(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		free_map(game->map->mapdata);
		free(game->moves_str);
		free(game->score_s);
		free(game->all_imgs);
		ft_printf("ESC pressed, you've left the game\n");
		exit(0);
	}
}

void	enemy_exit(t_game *game)
{
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free_map(game->map->mapdata);
	free(game->moves_str);
	free(game->score_s);
	free(game->all_imgs);
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
	free(game->all_imgs);
	ft_putstr_fd("The magic exit discovered, quest completed! ≽^• ⩊ •^≼ \n", 1);
	exit(0);
}
