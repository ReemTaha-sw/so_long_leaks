/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_update_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:34:32 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 21:05:38 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h" 

void	draw_ex_b(t_data *data, int i, int j)
{
	if (data->map[i][j] == EXIT)
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
				data->exit_locked_image, PIX_SIZE * j, PIX_SIZE * i);
		}
	}
	else if (data->map[i][j] == 'A')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->man.mg, PIX_SIZE * j, PIX_SIZE * i);
		data->map[i][j] = EXIT;
	}
}

void	draw_co_b(t_data *data, int i, int j)
{
	if (data->map[i][j] == COLLECTABLE)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
		mlx_put_image_to_window(data->mlx, data->win,
			data->collectable_image, PIX_SIZE * j, PIX_SIZE * i);
	}
}

void	draw_py_b(t_data *data, int i, int j)
{
	if (data->map[i][j] == PACMAN)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
		mlx_put_image_to_window(data->mlx, data->win,
			data->man.mg, PIX_SIZE * j, PIX_SIZE * i);
	}
}

void	draw_en_b(t_data *data, int i, int j)
{
	if (data->map[i][j] == ENEMY)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
		mlx_put_image_to_window(data->mlx, data->win,
			data->enemy_image, PIX_SIZE * j, PIX_SIZE * i);
	}
}

void	draw_b(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			draw_ex_b(data, i, j);
			draw_co_b(data, i, j);
			draw_py_b(data, i, j);
			draw_en_b(data, i, j);
			if (data->map[i][j] == WALL)
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall_image, PIX_SIZE * j, PIX_SIZE * i);
			else if (data->map[i][j] == EMPTY)
				mlx_put_image_to_window(data->mlx, data->win,
					data->empty_image, PIX_SIZE * j, PIX_SIZE * i);
		}
	}
	animate_collectibles(data);
}
