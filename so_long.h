/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 21:17:25 by rosman            #+#    #+#             */
/*   Updated: 2024/02/17 19:35:17 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include "libx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "git_next_line/get_next_line.h"

# define WALL '1'
# define EMPTY '0'
# define EXIT 'E'
# define COLLECTABLE 'C'
# define PACMAN 'P'
# define ENEMY 'X'
# define PIX_SIZE 40

enum e_EnemyState {
	MOVE_RIGHT,
	MOVE_LEFT
};

typedef struct s_pacman{
	int		x;
	int		y;
	char	*mg;
}				t_pacman;
typedef struct s_enemy{
	int					x;
	int					y;
	enum e_EnemyState	dir;
	struct s_enemy		*next;
}						t_enemy;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			map_width;
	int			map_height;
	int			pix_size;
	int			collectable_num;
	char		**map;
	char		**temp_map;
	char		*wall_image;
	char		*exit_image;
	char		*exit_locked_image;
	char		*collectable_image;
	char		*empty_image;
	char		*black_image;
	char		*enemy_image;
	t_pacman	exit;
	t_pacman	man;
	t_enemy		*enemies;
}				t_data;
char	*get_next_line(int fd);
void	is_rectangle(t_data *data);
void	check_edges(char **map, size_t height, t_data *data);
void	at_least_collectable(char **map, char c, t_data *data);
void	only_once(t_data *data);
void	is_valid_map(char **map, t_data *data);
void	is_valid_map_bonus(char **map, t_data *data);
int		is_everything_reachable(t_data *data);
void	put_map(t_data *data, char *file);
void	print_error(t_data *data, char *ms);
void	is_ber(char *file_name);
size_t	ft_len(char *map);
int		ft_strcmp(const char *str1, const char *str2);
void	draw(t_data *data);
void	check_map(t_data *data);
void	check_map_bonus(t_data *data);
int		exit_game(t_data *data);
void	animate_collectibles(t_data *data);
void	load_assets(t_data *data);
void	init_data(t_data *data);
void	remove_player(t_data *data);
void	update_player(t_data *data, char *img, int y, int x);
void	draw_bonus(t_data *data);
void	draw_b(t_data *data);
int		key_hook(int keycode, t_data *data);
int		key_hook_b(int keycode, t_data *data);
void	add_enemy(t_data *data, int x, int y);
t_enemy	*create_enemy(int x, int y, int dir, t_data *data);
void	read_file(t_data *data, char *file);
int		loop_hook_b(t_data *data);
void	delay(int milliseconds);
void	animate_enemy(t_data *data);
void	enemy(t_data *data, int new_x, int new_y);
void	update_player_b(t_data *data, char *img, int y, int x);
void	update_game_state_b(t_data *data, int dx, int dy);
void	destroy_enemies(t_data *data);
char	*ft_dup( char *s1);
void	only_once_b(t_data *data);
void	init_player(t_data *data);
char	*ft_itoa(int n);
void	number_in_win(int steps, t_data *data);
void	vaild_img(t_data *data);

#endif