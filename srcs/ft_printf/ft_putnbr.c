/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:38:05 by sacharai          #+#    #+#             */
/*   Updated: 2023/02/06 03:53:41 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *pos)
{
	long int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', pos);
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + 48, pos);
	else
	{
		ft_putnbr(nb / 10, pos);
		ft_putnbr(nb % 10, pos);
	}
}
