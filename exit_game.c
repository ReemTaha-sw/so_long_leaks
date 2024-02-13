/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:24:19 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 21:06:26 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeing_map(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->map_height)
	{
		free(data->map[i]);
		free(data->temp_map[i]);
		i++;
	}
	free(data->map);
	free(data->temp_map);
}

void	remove_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == PACMAN)
			{
				data->map[i][j] = EMPTY;
				break ;
			}
		}
	}
}

void	print_error(t_data *data, char *ms)
{
	freeing_map(data);
	ft_printf("Sorry invalid map 👎.\n");
	ft_printf("%s.\n", ms);
	destroy_enemies(data);
	exit(1);
}

int	exit_game(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	freeing_map(data);
	destroy_enemies(data);
	exit(0);
	return (0);
}
