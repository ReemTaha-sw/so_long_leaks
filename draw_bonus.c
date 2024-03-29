/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:13:31 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 21:06:04 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit_b(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit_image, PIX_SIZE * j, PIX_SIZE * i);
		mlx_put_image_to_window(data->mlx, data->win, data->man.mg,
			PIX_SIZE * j, PIX_SIZE * i);
		data->map[i][j] = EXIT;
	}
	else if (data->map[i][j] == EXIT)
	{
		if (data->collectable_num == 0)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->black_image, PIX_SIZE * j, PIX_SIZE * i);
			mlx_put_image_to_window(data->mlx, data->win,
				data->exit_image, PIX_SIZE * j, PIX_SIZE * i);
		}
		else
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
			mlx_put_image_to_window(data->mlx, data->win,
				data->exit_locked_image, PIX_SIZE * j, PIX_SIZE * i);
		}
	}
}

void	draw_collectable_b(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
	mlx_put_image_to_window(data->mlx, data->win,
		data->collectable_image, PIX_SIZE * j, PIX_SIZE * i);
}

void	draw_player_b(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
	mlx_put_image_to_window(data->mlx, data->win,
		data->man.mg, PIX_SIZE * j, PIX_SIZE * i);
}

void	draw_e(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
	mlx_put_image_to_window(data->mlx, data->win,
		data->enemy_image, PIX_SIZE * j, PIX_SIZE * i);
}

void	draw_bonus(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == WALL)
				mlx_put_image_to_window(data->mlx, data->win, data->wall_image,
					PIX_SIZE * j, PIX_SIZE * i);
			else if (data->map[i][j] == EMPTY)
				mlx_put_image_to_window(data->mlx, data->win, data->empty_image,
					PIX_SIZE * j, PIX_SIZE * i);
			else if (data->map[i][j] == EXIT || data->map[i][j] == 'A')
				draw_exit_b(data, i, j);
			else if (data->map[i][j] == COLLECTABLE)
				draw_collectable_b(data, i, j);
			else if (data->map[i][j] == PACMAN)
				draw_player_b(data, i, j);
			else if (data->map[i][j] == ENEMY)
				draw_e(data, i, j);
		}
	}
}
