/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:04:51 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 21:05:55 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collision_with_player(t_data *data, t_enemy *enemy)
{
	int	enemy_cell_map_x;
	int	enemy_cell_map_y;
	int	player_cell_map_x;
	int	player_cell_map_y;

	enemy_cell_map_x = enemy->x ;
	enemy_cell_map_y = enemy->y ;
	player_cell_map_x = data->man.x ;
	player_cell_map_y = data->man.y ;
	return ((enemy_cell_map_x == player_cell_map_x)
		&& (enemy_cell_map_y == player_cell_map_y));
}

void	check_next(int new_x, t_data *data,
enum e_EnemyState *state, t_enemy *enemy)
{
	int					new_cell_x;
	int					px;

	px = PIX_SIZE;
	new_cell_x = new_x / px;
	if (new_x >= 0 && new_x < px * data->map_width
		&& data->map[enemy->y / px][new_x / px] != WALL
			&& data->map[enemy->y / px][new_x / px] != COLLECTABLE
			&& data->map[enemy->y / px][new_x / px] != EXIT
			&& data->map[enemy->y / px][new_x / px] != ENEMY
			)
	{
		data->map[enemy->y / px][enemy->x / px] = EMPTY;
		enemy->x = new_x;
		data->map[enemy->y / px][new_cell_x] = ENEMY;
	}
	else
	{
		if (*state == MOVE_LEFT)
			*state = MOVE_RIGHT;
		else
			*state = MOVE_LEFT;
	}
}

void	update_enemy_position(t_data *data, t_enemy *enemy)
{
	int	new_x;

	if (enemy->dir == MOVE_RIGHT)
	{
		new_x = enemy->x + PIX_SIZE;
		check_next(new_x, data, &enemy->dir, enemy);
	}
	else if (enemy->dir == MOVE_LEFT)
	{
		new_x = enemy->x - PIX_SIZE;
		check_next(new_x, data, &enemy->dir, enemy);
	}
	if (check_collision_with_player(data, enemy))
	{
		delay(9000);
		exit_game(data);
	}
}

void	animate_enemy(t_data *data)
{
	t_enemy	*current;

	current = data->enemies;
	while (current)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->empty_image, current->x, current->y);
		update_enemy_position(data, current);
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy_image, current->x, current->y);
		current = current->next;
	}
}


int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		print_error(&data, "The input must be like : ./so_long <map_file.ber>");
	is_ber(argv[1]);
	init_data(&data);
	read_file(&data, argv[1]);
	// data.map = put_map(&data, argv[1]);
	// data.temp_map = put_map(&data, argv[1]);
	put_map(&data, argv[1]);
	check_map_bonus(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, PIX_SIZE * data.map_width,
			PIX_SIZE * data.map_height, "SUPER MARIO");
	data.img = mlx_new_image(data.mlx, PIX_SIZE * data.map_width,
			PIX_SIZE * data.map_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	load_assets(&data);
	mlx_hook(data.win, 17, 0, exit_game, &data);
	mlx_hook(data.win, 2, 0, key_hook_b, &data);
	mlx_loop_hook(data.mlx, loop_hook_b, &data);
	mlx_loop(data.mlx);
	// exit_game(&data);
	return (0);
}
