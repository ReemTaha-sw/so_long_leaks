/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:29:14 by rosman            #+#    #+#             */
/*   Updated: 2024/02/16 20:55:35 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy(t_data *data, int x, int y)
{
	static enum e_EnemyState	state;
	t_enemy						*new_enemy;

	if (rand() % 2 == 0)
		state = MOVE_LEFT;
	else
		state = MOVE_RIGHT;
	new_enemy = malloc(sizeof(t_enemy));
	if (new_enemy)
	{
		new_enemy->x = x * PIX_SIZE;
		new_enemy->y = y * PIX_SIZE;
		new_enemy->dir = state;
		new_enemy->next = data->enemies;
		data->enemies = new_enemy;
	}
}

void	free_all_enemies(t_enemy *enemy, t_data *data)
{
	t_enemy	*next_enemy;

	while (enemy)
	{
		next_enemy = enemy->next;
		free(enemy);
		enemy = next_enemy;
	}
	data->enemies = NULL;
}

void	destroy_enemies(t_data *data)
{
	free_all_enemies(data->enemies, data);
	data->enemies = NULL;
}
