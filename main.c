/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:09:47 by rosman            #+#    #+#             */
/*   Updated: 2024/02/17 19:43:48 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit_game(data);
	else if (keycode == 0 || keycode == 123)
		update_player(data, "assets/mario_left.xpm", -PIX_SIZE, 0);
	else if (keycode == 2 || keycode == 124)
		update_player(data, "assets/mario_right.xpm", PIX_SIZE, 0);
	else if (keycode == 1 || keycode == 125)
		update_player(data, "assets/mario_front.xpm", 0, PIX_SIZE);
	else if (keycode == 13 || keycode == 126)
		update_player(data, "assets/mario_back.xpm", 0, -PIX_SIZE);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (write(1, "invalid arguments", 17), 1);
	is_ber(argv[1]);
	init_data(&data);
	read_file(&data, argv[1]);
	put_map(&data, argv[1]);
	check_map(&data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, PIX_SIZE * data.map_width,
			PIX_SIZE * data.map_height, "SUPER MARIO");
	data.img = mlx_new_image(data.mlx, PIX_SIZE * data.map_width,
			PIX_SIZE * data.map_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	load_assets(&data);
	mlx_hook(data.win, 17, 0, exit_game, &data);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
