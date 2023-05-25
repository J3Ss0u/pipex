/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:40:44 by sacharai          #+#    #+#             */
/*   Updated: 2022/11/07 05:54:16 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length(int n)
{
	size_t	i;

	i = 1;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_num;
	size_t		c;
	long int	num;

	num = n;
	c = length(n);
	if (n < 0)
	{
		num *= -1;
		c++;
	}
	str_num = (char *)malloc(sizeof(char) * (c + 1));
	if (!str_num)
		return (NULL);
	str_num[c] = 0;
	while (c--)
	{
		str_num[c] = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		str_num[0] = '-';
	return (str_num);
}
