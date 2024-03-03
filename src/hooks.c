/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:11:48 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/03 21:58:03 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	score_exit_check(t_game *game)
{
	if (game->current_score == game->map->total_score)
	{
		game->all_imgs->e_closed_img[0].enabled = 0;
		game->all_imgs->e_open_img[0].enabled = 1;
		game->map->exit_open = 1;
	}
}

void	arrow_key_pressed(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS
		&& game->map->player_x < (game->map->col_count - 2))
		right_move(game);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS
		&& game->map->player_x > 1)
		left_move(game);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS
		&& game->map->player_y > 1)
		up_move(game);
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS
		&& game->map->player_y < (game->map->row_count - 2))
		down_move(game);
}

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_game		*game;

	game = (t_game *) param;
	esc_pressed_termination(keydata, game);
	arrow_key_pressed(keydata, game);
	score_exit_check(game);
	print_header(game);
}
