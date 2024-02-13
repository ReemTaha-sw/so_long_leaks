/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:17:25 by hankhali          #+#    #+#             */
/*   Updated: 2024/02/07 20:52:42 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strjoin(char *string1, char *string2)
{
	char	*result;
	size_t	i;
	size_t	length1;
	size_t	length2;

	i = 0;
	if (!string1 || !string2)
		return (NULL);
	length1 = ft_strlen(string1);
	length2 = ft_strlen(string2);
	result = (char *)malloc((length1 + length2 + 1) * sizeof(char));
	while (i < length1)
	{
		result[i] = string1[i];
		i++;
	}
	i = 0;
	while (i < length2)
	{
		result[length1 + i] = string2[i];
		i++;
	}
	result[length1 + length2] = '\0';
	free(string1);
	return (result);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dest;

	len = ft_strlen(s1);
	i = 0;
	dest = (char *)malloc(sizeof(*dest) * (len + 1));
	if (dest != NULL)
	{
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
