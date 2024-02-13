/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:28:07 by rosman            #+#    #+#             */
/*   Updated: 2024/02/11 20:50:20 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_len(char *map)
{
	size_t	len;

	len = 0;
	while (map[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char	*dst, const char	*src, size_t dstsize)
{
	size_t	i;
	size_t	spacs;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dstsize == 0)
		return (src_len);
	if (dstsize > 0)
		spacs = dstsize - 1;
	else
		spacs = 0;
	i = 0;
	while (i < spacs && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_dup( char *s1)
{
	size_t	len;
	char	*new_str;

	len = ft_len(s1) + 1;
	new_str = (char *)malloc(len);
	if (new_str != NULL)
		ft_strlcpy(new_str, s1, len);
	return (new_str);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

void	read_file(t_data *data, char *file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file :");
		exit (1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->map_width = ft_len(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map_height = i;
	close(fd);
}
