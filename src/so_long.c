/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:33:34 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/02 17:22:42 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int32_t	main(int argc, char **argv)
{
	int32_t		width;
	int32_t		height;
	t_game		*game;
	t_game		game_var;

	error_arg(argc);
	game = &game_var;
	game->map = read_map(argv[1]);
	width = WIDTH * game->map->col_count;
	height = HEIGHT * game->map->row_count;
	game->mlx = mlx_init(width, height, "So_long: Mushroom hunting", false);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->all_imgs = get_images(game->mlx);
	game_content(game);
	mlx_key_hook(game->mlx, &ft_hooks, (void *) game);
	mlx_loop(game->mlx);
	return (EXIT_SUCCESS);
}
