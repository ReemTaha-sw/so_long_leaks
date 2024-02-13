/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:52:54 by rosman            #+#    #+#             */
/*   Updated: 2024/01/09 14:59:19 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putnbr(unsigned int n)
{
	if (n > 9)
		putnbr(n / 10);
	ft_print_char(n % 10 + '0');
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
	putnbr(n);
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}
