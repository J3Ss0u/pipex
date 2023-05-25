/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:54:37 by sacharai          #+#    #+#             */
/*   Updated: 2023/02/06 05:28:12 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putx(unsigned long int ptr, char x, int *len)
{
	unsigned long int	base;

	base = 16;
	if (ptr < base)
	{
		if (x == 'x')
			ft_putchar("0123456789abcdef"[ptr % base], len);
		else
			ft_putchar("0123456789ABCDEF"[ptr % base], len);
	}
	else
	{
		ft_putx(ptr / base, x, len);
		ft_putx(ptr % base, x, len);
	}
}
