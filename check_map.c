/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 13:51:10 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 19:16:31 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(t_data *data, int row, int col)
{
	int	i;
	int	new_row;
	int	new_col;
	int	*row_offsets;
	int	*col_offsets;

	i = 0;
	data->temp_map[row][col] = 1;
	row_offsets = (int []){-1, 0, 1, 0};
	col_offsets = (int []){0, 1, 0, -1};
	while (i < 4)
	{
		new_row = row + row_offsets[i];
		new_col = col + col_offsets[i];
		if (new_row >= 0 && new_row < data->map_height
			&& new_col >= 0 && new_col < data->map_width
			&& data->map[new_row][new_col] != '1'
			&& !data->temp_map[new_row][new_col])
			dfs(data, new_row, new_col);
		i++;
	}
}

int	is_everything_reachable(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	x = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
			data->temp_map[i][j] = 0;
	}
	dfs(data, data->man.y, data->man.x);
	while (++x < data->map_height)
	{
		y = -1;
		while (++y < data->map_width)
			if ((data->map[x][y] == 'C' || data->map[x][y] == 'E')
			&& !data->temp_map[x][y])
				return (0);
	}
	return (1);
}

void	is_ber(char *file_name)
{
	size_t	filename_len;
	size_t	extension_len;
	char	*extension;

	filename_len = ft_len(file_name);
	extension = ".ber";
	extension_len = ft_len(extension);
	if (filename_len >= extension_len
		&& ft_strcmp(file_name + filename_len - extension_len, extension) != 0)
	{
		ft_printf("The filename DOES NOT ends with \".ber\"");
		exit(1);
	}
}

void	check_map(t_data *data)
{
	is_rectangle(data);
	check_edges(data->map, data->map_height, data);
	at_least_collectable(data->map, 'C', data);
	only_once(data);
	if (!is_everything_reachable(data))
	{
		print_error(data, "Not all collectables or exit are reachable 👎");
		exit_game(data);
	}
	is_valid_map(data->map, data);
}
