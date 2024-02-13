/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_collect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:47:08 by rosman            #+#    #+#             */
/*   Updated: 2024/02/13 21:57:52 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**put_img(void)
{
	static char	*collectible_frames[4];

	collectible_frames[0] = "assets/collectable/collectable_r.xpm";
	collectible_frames[1] = "assets/collectable/collectable_f.xpm";
	collectible_frames[2] = "assets/collectable/collectable_l.xpm";
	collectible_frames[3] = "assets/collectable/collectable_f.xpm";
	return (collectible_frames);
}

void	animate_collectibles(t_data *data)
{
	static int	collectible_frames_counter = 0;
	int			i;
	int			j;
	char		*current_image;
	char		**collectible_frames;

	collectible_frames = put_img();
	i = -1;
	while (++i < data->map_height)
	{
		j = -1;
		while (++j < data->map_width)
		{
			if (data->map[i][j] == COLLECTABLE)
			{
				current_image = collectible_frames[collectible_frames_counter];
				// mlx_clear_window();
				mlx_put_image_to_window(data->mlx, data->win,
					mlx_xpm_file_to_image(data->mlx, current_image,
						&data->pix_size, &data->pix_size),
					PIX_SIZE * j, PIX_SIZE * i);
			}
		}
	}
	collectible_frames_counter = (collectible_frames_counter + 1) % 4;
}
