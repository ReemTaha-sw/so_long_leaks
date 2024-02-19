/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:43:08 by rosman            #+#    #+#             */
/*   Updated: 2024/02/16 21:09:23 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rectangle(t_data *data)
{
	size_t	i;
	int		j;

	i = 0;
	if (data->map == NULL || data->map[0] == (void *)0)
		print_error(data, "Not RECTANGLE");
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j != data->map_width)
			print_error(data, "Not RECTANGLE");
		i++;
	}
	ft_printf("IS RECTANGLE👍.\n");
}

void	check_edges(char **map, size_t height, t_data *data)
{
	size_t	i;
	size_t	width;

	i = 0;
	if (map == NULL || *map == NULL)
	{
		ft_printf("Not all edges all WALLS");
		exit_game(data);
	}
	width = ft_len(*map);
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			print_error(data, "Not all edges all WALLS");
		i++;
	}
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			print_error(data, "Not all edges all WALLS");
		i++;
	}
	ft_printf("Edges are filled with '1' 👍.\n");
}

void	at_least_collectable(char **map, char c, t_data *data)
{
	char	*current_string;

	if (map == NULL)
		print_error(data, "There is No collectable");
	while (*map != NULL)
	{
		current_string = *map;
		while (*current_string != '\0')
		{
			if (*current_string == c)
			{
				ft_printf("There is a collectable 👍.\n");
				return ;
			}
			current_string++;
		}
		map++;
	}
	print_error(data, "There is No collectable");
}

void	init_player(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'P')
			{
				data->man.x = j;
				data->man.y = i;
			}
			else if (data->map[i][j] == 'C')
				data->collectable_num++;
		}
	}
}

void	only_once(t_data *data)
{
	int		counter_p;
	int		counter_e;
	int		i;
	int		j;

	i = -1;
	counter_p = 0;
	counter_e = 0;
	init_player(data);
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == PACMAN)
				counter_p++;
			else if (data->map[i][j] == EXIT)
				counter_e++;
		}
	}
	if (counter_p != 1 || counter_e != 1 || data->collectable_num < 1)
		print_error(data, "More or Non : 'P', 'E', 'C'");
}
