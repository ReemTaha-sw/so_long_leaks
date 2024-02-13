/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:14:26 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 21:07:03 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] == ENEMY)
		exit_game(data);
	remove_player(data);
	data->man.x = new_x;
	data->man.y = new_y;
	if (data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] == EXIT &&
		data->collectable_num != 0)
		data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] = 'A';
	else
		data->map[new_y / PIX_SIZE][new_x / PIX_SIZE] = PACMAN;
}

void	update_game_state(t_data *data, int dx, int dy)
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
		draw(data);
		ft_printf("Number of steps : %i\n", steps);
	}
}

void	update_player(t_data *data, char *img, int y, int x)
{
	data->man.mg = mlx_xpm_file_to_image(data->mlx,
			img, &data->pix_size, &data->pix_size);
	update_game_state(data, y, x);
}
