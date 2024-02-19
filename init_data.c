/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:50:25 by rosman            #+#    #+#             */
/*   Updated: 2024/02/16 21:51:48 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_man(t_data *data, int j, int i)
{
	data->man.x = j * data->pix_size;
	data->man.y = i * data->pix_size;
	data->man.mg = mlx_xpm_file_to_image(data->mlx, "assets/mario_front.xpm",
			&data->pix_size, &data->pix_size);
	if (!data->man.mg)
		exit_game(data);
}

void	put_p_e(t_data *data)
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
				put_man(data, j, i);
			else if (data->map[i][j] == EXIT)
			{
				data->exit.x = j * data->pix_size;
				data->exit.y = i * data->pix_size;
			}
		}
	}
}

void	load_assets(t_data *data)
{
	data->wall_image = mlx_xpm_file_to_image(data->mlx,
			"assets/wall.xpm", &data->pix_size, &data->pix_size);
	data->collectable_image = mlx_xpm_file_to_image(data->mlx,
			"assets/collectable.xpm", &data->pix_size, &data->pix_size);
	data->empty_image = mlx_xpm_file_to_image(data->mlx,
			"assets/empty.xpm", &data->pix_size, &data->pix_size);
	data->exit_image = mlx_xpm_file_to_image(data->mlx,
			"assets/exit/e_full_open.xpm", &data->pix_size, &data->pix_size);
	data->exit_locked_image = mlx_xpm_file_to_image(data->mlx,
			"assets/exit/e_full_closed.xpm", &data->pix_size, &data->pix_size);
	data->black_image = mlx_xpm_file_to_image(data->mlx,
			"assets/exit/black1.xpm", &data->pix_size, &data->pix_size);
	data->enemy_image = mlx_xpm_file_to_image(data->mlx,
			"assets/x.xpm", &data->pix_size, &data->pix_size);
	data->exit.mg = mlx_xpm_file_to_image(data->mlx,
			"assets/exit/e_full_closed.xpm", &data->pix_size, &data->pix_size);
	vaild_img(data);
	put_p_e(data);
	draw(data);
}

void	put_map(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	i = 0;
	data->map = (char **)malloc((data->map_height + 1) * sizeof(char *));
	data->temp_map = (char **)malloc((data->map_height + 1) * sizeof(char *));
	if (!data->map || !data->temp_map)
		exit(1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map[i] = ft_strdup(line);
		data->temp_map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map[i] = NULL;
	data->temp_map[i] = NULL;
	close(fd);
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->pix_size = PIX_SIZE;
	data->map = NULL;
	data->temp_map = NULL;
	data->wall_image = NULL;
	data->exit_image = NULL;
	data->exit_locked_image = NULL;
	data->collectable_image = NULL;
	data->empty_image = NULL;
	data->black_image = NULL;
	data->enemy_image = NULL;
	data->man.x = 0;
	data->man.y = 0;
	data->man.mg = NULL;
	data->collectable_num = 0;
	data->enemies = NULL;
}
