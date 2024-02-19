/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:14:26 by rosman            #+#    #+#             */
/*   Updated: 2024/02/17 19:58:22 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	loop_hook_b(t_data *data)
{
	animate_enemy(data);
	delay(3000);
	animate_collectibles(data);
	delay(5000);
	return (0);
}

void	delay(int milliseconds)
{
	long	iterations;

	iterations = milliseconds * 10000;
	while (iterations > 0)
		iterations--;
}

void	update_player_b(t_data *data, char *img, int y, int x)
{
	data->man.mg = mlx_xpm_file_to_image(data->mlx,
			img, &data->pix_size, &data->pix_size);
	if (!data->man.mg)
		exit_game(data);
	update_game_state_b(data, y, x);
}

void	update_game_state_b(t_data *data, int dx, int dy)
{
	int			new_x;
	int			new_y;
	static int	steps;

	new_x = data->man.x + dx;
	new_y = data->man.y + dy;
	if (data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] != WALL)
	{
		steps++;
		if (data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] == COLLECTABLE)
		{
			data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] = EMPTY;
			data->collectable_num--;
		}
		if (data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] == EXIT &&
			data->collectable_num == 0)
			exit_game(data);
		enemy(data, new_x, new_y);
		draw_b(data);
		number_in_win(steps, data);
		ft_printf("Number of steps : %i\n", steps);
	}
}

int	key_hook_b(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_game(data);
	else if (keycode == 0 || keycode == 123)
		update_player_b(data, "assets/mario_left.xpm", -PIX_SIZE, 0);
	else if (keycode == 2 || keycode == 124)
		update_player_b(data, "assets/mario_right.xpm", PIX_SIZE, 0);
	else if (keycode == 1 || keycode == 125)
		update_player_b(data, "assets/mario_front.xpm", 0, PIX_SIZE);
	else if (keycode == 13 || keycode == 126)
		update_player_b(data, "assets/mario_back.xpm", 0, -PIX_SIZE);
	return (0);
}
