/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 11:41:06 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/02/25 22:19:59 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_header(t_game *game)
{
	char	*moves_str_prev;
	char	*moves_str;
	char	*score_str_prev;
	char	*score_str;
	int		s_y;

	s_y = (game->map->row_count - 1) * HEIGHT + 10;
	moves_str_prev = game->moves_str;
	free(moves_str_prev);
	moves_str = ft_itoa(game->moves_c);
	game->moves_str = ft_strjoin("MushMoves - ", moves_str);
	free(moves_str);
	mlx_delete_image(game->mlx, game->moves_img);
	game->moves_img = mlx_put_string(game->mlx, game->moves_str, game->s_x, 0);
	score_str_prev = game->score_s;
	free(score_str_prev);
	score_str = ft_itoa(game->current_score);
	game->score_s = ft_strjoin("MushroomScore - ", score_str);
	free(score_str);
	mlx_delete_image(game->mlx, game->score_img);
	game->score_img = mlx_put_string(game->mlx, game->score_s, game->s_x, s_y);
}

void	put_img(mlx_t *mlx, t_map *map, mlx_image_t *img, char mapitem)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row_count)
	{
		x = 0;
		while (x < map->col_count)
		{
			if (map->mapdata[y][x] == mapitem)
			{
				if (mlx_image_to_window(mlx, img, x * WIDTH, y * HEIGHT) < 0)
					ft_error();
			}
			x++;
		}
		y++;
	}
}

void	game_content(t_game *game)
{
	int	s_x;
	int	s_y;

	s_x = (game->map->col_count * WIDTH) / 2 - 80;
	game->s_x = s_x;
	s_y = (game->map->row_count - 1) * HEIGHT + 10;
	put_img(game->mlx, game->map, game->all_imgs->wall_img, '1');
	put_img(game->mlx, game->map, game->all_imgs->enemy_img, 'A');
	put_img(game->mlx, game->map, game->all_imgs->collect_img, 'C');
	put_img(game->mlx, game->map, game->all_imgs->e_open_img, 'E');
	put_img(game->mlx, game->map, game->all_imgs->e_closed_img, 'E');
	put_img(game->mlx, game->map, game->all_imgs->path_img, '0');
	put_img(game->mlx, game->map, game->all_imgs->player_img, 'P');
	game->moves_str = ft_strjoin("MushMoves - ", "0");
	game->score_img = mlx_put_string(game->mlx, game->moves_str, s_x, 10);
	game->moves_c = 0;
	game->score_s = ft_strjoin("MushroomScore - ", "0");
	game->moves_img = mlx_put_string(game->mlx, game->score_s, s_x, s_y);
	game->current_score = 0;
	game->all_imgs->e_open_img[0].enabled = 0;
}

void	new_img(char *path, mlx_t *mlx, mlx_texture_t **tex, mlx_image_t **img)
{
	*tex = mlx_load_png(path);
	if (!*tex)
		ft_error();
	*img = mlx_texture_to_image(mlx, *tex);
	if (!*img)
		ft_error();
	mlx_delete_texture(*tex);
}

t_images	*get_images(mlx_t *mlx)
{
	t_images	*imgs;

	imgs = (t_images *) malloc(1 * sizeof(t_images));
	if (!imgs)
		ft_error();
	new_img("./img/collect.png", mlx, &imgs->collect_tex, &imgs->collect_img);
	new_img("./img/enemy.png", mlx, &imgs->enemy_tex, &imgs->enemy_img);
	new_img("./img/e_open.png", mlx, &imgs->e_open_tex, &imgs->e_open_img);
	new_img("./img/e_closed.png", mlx, &imgs->e_closd_tex, &imgs->e_closed_img);
	new_img("./img/path.png", mlx, &imgs->path_tex, &imgs->path_img);
	new_img("./img/player.png", mlx, &imgs->player_tex, &imgs->player_img);
	new_img("./img/wall.png", mlx, &imgs->wall_tex, &imgs->wall_img);
	return (imgs);
}
