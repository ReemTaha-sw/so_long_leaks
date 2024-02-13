/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:46:15 by rosman            #+#    #+#             */
/*   Updated: 2024/02/13 20:50:56 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	nbr_len(int no)
{
	int	i;

	i = 0;
	if (no == -2147483648)
		return (11);
	if (no < 0)
	{
		no = -no;
		i++;
	}
	while (no > 9)
	{
		no /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*write_nbr(char *str, long int n, int i)
{
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	i--;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		i--;
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	char		*str;
	long int	nb;

	i = nbr_len(n);
	nb = n;
	str = (char *)malloc(sizeof(char) * (i +1));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str = write_nbr(str, n, i);
	str[i] = '\0';
	return (str);
}
