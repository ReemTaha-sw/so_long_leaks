/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 21:35:41 by rosman            #+#    #+#             */
/*   Updated: 2024/02/16 20:56:33 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_map(char **map, t_data *data)
{
	char	current_char;
	char	*current_string;

	if (map == NULL)
		print_error(data, "Contains Invalid Characters");
	while (*map != NULL)
	{
		current_string = *map;
		while (*current_string != '\0')
		{
			current_char = *current_string;
			if (current_char != 'E' && current_char != 'P'
				&& current_char != '0' && current_char != '1'
				&& current_char != 'C')
				print_error(data, "Contains Invalid Characters");
			current_string++;
		}
		map++;
	}
	ft_printf("The map contains only valid characters 👍.\n");
}

void	is_valid_map_bonus(char **map, t_data *data)
{
	char	current_char;
	char	*current_string;

	if (map == NULL)
		print_error(data, "Contains Invalid Characters");
	while (*map != NULL)
	{
		current_string = *map;
		while (*current_string != '\0')
		{
			current_char = *current_string;
			if (current_char != 'E' && current_char != 'P'
				&& current_char != '0' && current_char != '1'
				&& current_char != 'C' && current_char != 'X')
				print_error(data, "Contains Invalid Characters");
			current_string++;
		}
		map++;
	}
	ft_printf("The map contains only valid characters 👍.\n");
}

void	only_once_b(t_data *data)
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
			else if (data->map[i][j] == ENEMY)
				add_enemy(data, j, i);
		}
	}
	if (counter_p != 1 || counter_e != 1 || data->collectable_num < 1)
		print_error(data, "More or Non : 'P', 'E', 'C'");
}

void	check_map_bonus(t_data *data)
{
	is_rectangle(data);
	check_edges(data->map, data->map_height, data);
	at_least_collectable(data->map, 'C', data);
	only_once_b(data);
	is_valid_map_bonus(data->map, data);
	if (!is_everything_reachable(data))
	{
		print_error(data, "Not all collectables or exit are reachable 👎");
		exit_game(data);
	}
}
