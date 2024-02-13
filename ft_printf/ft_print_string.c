/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:12:35 by rosman            #+#    #+#             */
/*   Updated: 2024/01/09 14:59:16 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *c)
{
	int	count;

	count = 0;
	if (!c)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (c[count])
	{
		write(1, &c[count], 1);
		count++;
	}
	return (count);
}
