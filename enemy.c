/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:29:14 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 19:41:33 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	add_enemy(t_data *data, int x, int y)
{
static enum e_EnemyState state;

    if (rand() % 2 == 0)
        state = MOVE_LEFT;
    else
        state = MOVE_RIGHT;
    // Create the new enemy
    t_enemy *new_enemy = malloc(sizeof(t_enemy));
    if (new_enemy) {
        new_enemy->x = x * PIX_SIZE;
        new_enemy->y = y * PIX_SIZE;
        new_enemy->dir = state;
        new_enemy->next = data->enemies;
        data->enemies = new_enemy;
    }
    // return new_enemy;
}

void free_all_enemies(t_enemy *enemy, t_data *data) {
    while (enemy) {
        t_enemy *next_enemy = enemy->next;
        free(enemy);
        enemy = next_enemy;
    }
	data->enemies = NULL;
}

// t_enemy	*create_enemy(int x, int y, int dir)
// {
// 	t_enemy	*enemy;

// 	enemy = malloc(sizeof(t_enemy));
// 	if (enemy)
// 	{
// 		enemy->x = x * PIX_SIZE;
// 		enemy->y = y * PIX_SIZE;
// 		enemy->dir = dir;
// 		free(enemy);
// 		enemy->next = NULL;
// 	}
// 	return (enemy);
// }

// void	add_enemy(t_data *data, int x, int y)
// {
// 	t_enemy						*new_enemy;
// 	static enum e_EnemyState	state;

// 	if (rand() % 2 == 0)
// 		state = MOVE_LEFT;
// 	else
// 		state = MOVE_RIGHT;
// 	new_enemy = create_enemy(x, y, state);
// 	if (new_enemy)
// 	{
// 		new_enemy->next = data->enemies;
// 		data->enemies = new_enemy;
// 	}
// }

void	destroy_enemies(t_data *data)
{
	// t_enemy	*current_enemy;
	// t_enemy	*next_enemy;

	// current_enemy = data->enemies;
	// while (current_enemy != NULL)
	// {
	// 	next_enemy = current_enemy->next;
	// 	free(current_enemy);
	// 	current_enemy = next_enemy;
	// }
	// data->enemies = NULL;
	free_all_enemies(data->enemies,  data);
    data->enemies = NULL;
}
