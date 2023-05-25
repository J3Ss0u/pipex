/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:30:17 by sacharai          #+#    #+#             */
/*   Updated: 2023/02/12 10:43:35 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check(va_list arg, char c, int *l)
{
	if (!c)
		return ;
	if (c == 'c')
		ft_putchar((char)va_arg(arg, int), l);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), l);
	else if (c == 'p')
		ft_putptr(va_arg(arg, void *), l);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(arg, int), l);
	else if (c == 'x')
		ft_putx(va_arg(arg, unsigned int), c, l);
	else if (c == 'X')
		ft_putx(va_arg(arg, unsigned int), c, l);
	else if (c == 'u')
		ft_putunsigned(va_arg(arg, unsigned int), l);
	else if (c == '%')
		ft_putchar(c, l);
	else
		ft_putchar(c, l);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		pos;
	int		i;

	va_start(arg, format);
	i = write(1, "", 0);
	if (i < 0)
		return (-1);
	pos = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &pos);
		else
			ft_check(arg, format[++i], &pos);
	}
	va_end(arg);
	return (pos);
}
