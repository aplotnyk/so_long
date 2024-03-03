/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aplotnyk <aplotnyk@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:35:06 by aplotnyk          #+#    #+#             */
/*   Updated: 2024/03/03 22:04:16 by aplotnyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# define WIDTH 64
# define HEIGHT 64

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft/libft.h"
# include "../libs/libft/libft/get_next_line_bonus.h"
# include "../libs/libft/libft/ft_printf.h"

typedef struct imgs
{
	mlx_texture_t	*collect_tex;
	mlx_image_t		*collect_img;
	mlx_texture_t	*enemy_tex;
	mlx_image_t		*enemy_img;
	mlx_texture_t	*e_closd_tex;
	mlx_image_t		*e_closed_img;
	mlx_texture_t	*e_open_tex;
	mlx_image_t		*e_open_img;
	mlx_texture_t	*path_tex;
	mlx_image_t		*path_img;
	mlx_texture_t	*player_tex;
	mlx_image_t		*player_img;
	mlx_texture_t	*wall_tex;
	mlx_image_t		*wall_img;
}			t_images;

typedef struct map_check_data
{
	int			**visited;
	int			collect_found;
	int			exit_found;

}			t_map_check_data;

typedef struct map
{
	char	**mapdata;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	int		total_score;
	int		exit_open;
	int		row_count;
	int		col_count;
}			t_map;

typedef struct game
{
	mlx_t			*mlx;
	t_map			*map;
	t_images		*all_imgs;
	int				current_score;
	int				moves_c;
	char			*moves_str;
	char			*score_s;
	mlx_image_t		*moves_img;
	mlx_image_t		*score_img;
	int				s_x;

}			t_game;

//errors
void				error_arg(int argc);
void				error_msg(char *str);
void				ft_error(void);

//map
t_map				*read_map(char *mapname);
void				extension_check(char *mapname);
char				**load_map_content(char *mapname);
char				**fill_map_array(int fd);

//map_chars_check
void				map_is_rectangular(char	**map_content, t_map *ma);
void				map_walls_around(char **map_content);
void				valid_char_scan(char map_char);
int					player_pos_check(char map_char, int x, int y, t_map *map);
void				map_valid_chars_check(char **map_content, t_map *ma);

//map_path_check
void				map_valid_path_check(t_map	*map);
t_map_check_data	get_check_data(t_map *map);
int					**init_map_visited(t_map *map);
void				free_map_visited(int ***map, int curr_row);
void				path_check(int y, int x, char **maparr,
						t_map_check_data *check_vals);

//utils
int					free_map(char **map);
int					free_imgs(t_game *game);
void				valid_chars_check_res(int p, int e, int c, t_map *map);

//images
void				print_header(t_game *game);
t_images			*get_images(mlx_t *mlx);
void				new_img(char *path, mlx_t *mlx, mlx_texture_t **tex,
						mlx_image_t **img);
void				game_content(t_game *game);
void				put_img(mlx_t *mlx, t_map *map, mlx_image_t *img,
						char mapitem);

//hooks
void				ft_hooks(mlx_key_data_t keydata, void *param);
void				arrow_key_pressed(mlx_key_data_t keydata, t_game *game);
void				score_exit_check(t_game *game);

//moves
void				collect_check(t_game *game);
void				right_move(t_game *game);
void				left_move(t_game *game);
void				up_move(t_game *game);
void				down_move(t_game *game);

//close_game
void				esc_pressed_termination(mlx_key_data_t keydata,
						t_game *game);
void				enemy_exit(t_game *game);
void				final_exit(t_game *game);

#endif