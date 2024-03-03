/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 20:00:05 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/03 22:00:11 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// void	right_move(t_game *game)
// {
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == 'C')
// 		game->current_score += 1;
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == '1')
// 		return ;
// 	// if (game->map->mapdata[game->map->player_y][game->map->player_x + 1]
//                                                                        == 'E'
// 	// 	&& game->current_score != game->map->total_score)
// 	// 	return ;
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == 'E'
// 		&& game->current_score == game->map->total_score)
// 		final_exit(game);
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == 'A')
// 		enemy_exit(game);
// 	else
// 	{
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = '0';
// 		game->map->player_x += 1;
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = 'P';
// 		game->moves_c += 1;
// 		put_img(game->mlx, game->map, game->all_imgs->path_img, '0');
// 		put_img(game->mlx, game->map, game->all_imgs->player_img, 'P');
// 	}
// 	ft_printf("Mush moves: %d\n", game->moves_c);
// }

// void	left_move(t_game *game)
// {
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == 'C')
// 		game->current_score += 1;
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == '1')
// 		return ;
// 	// if (game->map->mapdata[game->map->player_y][game->map->player_x - 1]
//                                                                        == 'E'
// 	// 	&& game->current_score != game->map->total_score)
// 	// 	return ;
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == 'E'
// 		&& game->current_score == game->map->total_score)
// 		final_exit(game);
// 	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == 'A')
// 		enemy_exit(game);
// 	else
// 	{
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = '0';
// 		game->map->player_x -= 1;
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = 'P';
// 		game->moves_c += 1;
// 		put_img(game->mlx, game->map, game->all_imgs->path_img, '0');
// 		put_img(game->mlx, game->map, game->all_imgs->player_img, 'P');
// 	}
// 	ft_printf("Mush moves: %d\n", game->moves_c);
// }

// void	up_move(t_game *game)
// {
// 	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == 'C')
// 		game->current_score += 1;
// 	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == '1')
// 		return ;
// 	// if (game->map->mapdata[game->map->player_y - 1][game->map->player_x]
//                                                                        == 'E'
// 	// 	&& game->current_score != game->map->total_score)
// 	// 	return ;
// 	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == 'E'
// 		&& game->current_score == game->map->total_score)
// 		final_exit(game);
// 	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == 'A')
// 		enemy_exit(game);
// 	else
// 	{
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = '0';
// 		game->map->player_y -= 1;
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = 'P';
// 		game->moves_c += 1;
// 		put_img(game->mlx, game->map, game->all_imgs->path_img, '0');
// 		put_img(game->mlx, game->map, game->all_imgs->player_img, 'P');
// 	}
// 	ft_printf("Mush moves: %d\n", game->moves_c);
// }

// void	down_move(t_game *game)
// {
// 	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'C')
// 		game->current_score += 1;
// 	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == '1')
// 		return ;
// 	// if (game->map->mapdata[game->map->player_y + 1][game->map->player_x]
//                                                                        == 'E'
// 	// 	&& game->current_score != game->map->total_score)
// 	// 	return ;
// 	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'E'
// 		&& game->current_score == game->map->total_score)
// 		final_exit(game);
// 	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'A')
// 		enemy_exit(game);
// 	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'C')
// 		eat_collect(game);
// 	else
// 	{
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = '0';
// 		game->map->player_y += 1;
// 		game->map->mapdata[game->map->player_y][game->map->player_x] = 'P';
// 		game->moves_c += 1;
// 		put_img(game->mlx, game->map, game->all_imgs->path_img, '0');
// 		put_img(game->mlx, game->map, game->all_imgs->player_img, 'P');
// 	}
// 	ft_printf("Mush moves: %d\n", game->moves_c);
// }

void	collect_check(t_game *game)
{
	int	i;
	int	coll_x;
	int	coll_y;

	i = 0;
	if (game->map->mapdata[game->map->player_y][game->map->player_x] == 'C')
	{
		game->map->mapdata[game->map->player_y][game->map->player_x] = '0';
		while (i < game->map->total_score)
		{
			coll_x = (size_t) game->all_imgs->collect_img->instances[i].x;
			coll_y = (size_t) game->all_imgs->collect_img->instances[i].y;
			if (coll_x / WIDTH == game->map->player_x
				&& coll_y / HEIGHT == game->map->player_y)
				game->all_imgs->collect_img->instances[i].enabled = 0;
			i++;
		}
	}
}

void	right_move(t_game *game)
{
	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == 'C')
		game->current_score += 1;
	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == '1')
		return ;
	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == 'E'
		&& game->current_score == game->map->total_score)
		final_exit(game);
	if (game->map->mapdata[game->map->player_y][game->map->player_x + 1] == 'A')
		enemy_exit(game);
	game->map->player_x += 1;
	game->moves_c += 1;
	game->all_imgs->player_img->instances[0].x += WIDTH;
	collect_check(game);
	ft_printf("Mush moves: %d\n", game->moves_c);
}

void	left_move(t_game *game)
{
	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == 'C')
		game->current_score += 1;
	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == '1')
		return ;
	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == 'E'
		&& game->current_score == game->map->total_score)
		final_exit(game);
	if (game->map->mapdata[game->map->player_y][game->map->player_x - 1] == 'A')
		enemy_exit(game);
	game->map->player_x -= 1;
	game->moves_c += 1;
	game->all_imgs->player_img->instances[0].x -= WIDTH;
	collect_check(game);
	ft_printf("Mush moves: %d\n", game->moves_c);
}

void	up_move(t_game *game)
{
	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == 'C')
		game->current_score += 1;
	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == '1')
		return ;
	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == 'E'
		&& game->current_score == game->map->total_score)
		final_exit(game);
	if (game->map->mapdata[game->map->player_y - 1][game->map->player_x] == 'A')
		enemy_exit(game);
	game->map->player_y -= 1;
	game->moves_c += 1;
	game->all_imgs->player_img->instances[0].y -= WIDTH;
	collect_check(game);
	ft_printf("Mush moves: %d\n", game->moves_c);
}

void	down_move(t_game *game)
{
	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'C')
		game->current_score += 1;
	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == '1')
		return ;
	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'E'
		&& game->current_score == game->map->total_score)
		final_exit(game);
	if (game->map->mapdata[game->map->player_y + 1][game->map->player_x] == 'A')
		enemy_exit(game);
	game->map->player_y += 1;
	game->moves_c += 1;
	game->all_imgs->player_img->instances[0].y += WIDTH;
	collect_check(game);
	ft_printf("Mush moves: %d\n", game->moves_c);
}
