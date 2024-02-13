/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:31:04 by rosman            #+#    #+#             */
/*   Updated: 2024/01/09 14:59:13 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pointer_ft(unsigned long long n)
{
	if (n >= 16)
	{
		pointer_ft(n / 16);
		pointer_ft(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_char(n % 10 + '0');
		else
			ft_print_char(n - 10 + 'a');
	}
}

int	ft_print_pointer(void *ptr)
{
	int					count;
	unsigned long long	n;

	count = 2;
	n = (unsigned long long) ptr;
	write(1, "0x", 2);
	pointer_ft(n);
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}
