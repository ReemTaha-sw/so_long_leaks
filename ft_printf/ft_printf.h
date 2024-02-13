/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosman <rosman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:14:53 by rosman            #+#    #+#             */
/*   Updated: 2024/01/09 14:59:31 by rosman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_string(char *c);
int	ft_print_digit(long n, int base, char x);
int	ft_print_pointer(void *ptr);
int	ft_print_unsigned(unsigned int n);

#endif