/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 05:28:27 by sacharai          #+#    #+#             */
/*   Updated: 2023/02/06 05:29:13 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nb, int *pos)
{
	if (nb >= 10)
	{
		ft_putunsigned(nb / 10, pos);
		ft_putunsigned(nb % 10, pos);
	}
	else
		ft_putchar(nb + '0', pos);
}
