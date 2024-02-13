/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:19:10 by rosman            #+#    #+#             */
/*   Updated: 2024/01/09 14:59:23 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_string(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_digit((long)va_arg(ap, int), 10, 0);
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(ap, int));
	else if (specifier == 'x')
		count += ft_print_digit((long)va_arg(ap, unsigned int), 16, 'x');
	else if (specifier == 'X')
		count += ft_print_digit((long)va_arg(ap, unsigned int), 16, 'X');
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		counter;
	int		i;
	va_list	ap;

	va_start(ap, format);
	counter = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			counter += print_format(format[i + 1], ap);
			i++;
		}
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}

// int	main(void)
// {
// 	ft_printf("hi = %X", -6000023);
// }
