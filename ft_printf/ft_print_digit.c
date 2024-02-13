/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:12:38 by rosman            #+#    #+#             */
/*   Updated: 2024/01/09 14:59:08 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(long n, int base, char x)
{
	int		count;
	char	*symbols;

	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-n, base, x) + 1);
	}
	else if (n < base)
	{
		if (base == 16 && x == 'X' && n >= 10 && n <= 16)
			return (ft_print_char(symbols[n] - 'a' + 'A'));
		else
			return (ft_print_char(symbols[n]));
	}
	else
	{
		count = ft_print_digit(n / base, base, x);
		return (count + ft_print_digit(n % base, base, x));
	}
}
