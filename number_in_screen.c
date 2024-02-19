/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_in_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:16:35 by rosman            #+#    #+#             */
/*   Updated: 2024/02/16 20:47:03 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	number_in_win(int steps, t_data *data)
{
	char	*steps_string;

	steps_string = ft_itoa(steps);
	mlx_string_put(data->mlx, data->win, 140, 20, 0x00ffffff, steps_string);
	mlx_string_put(data->mlx, data->win,
		20, 20, 0x00ffffff, "Number of steps :");
	free(steps_string);
}
