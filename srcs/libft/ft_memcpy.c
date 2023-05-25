/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:58:33 by sacharai          #+#    #+#             */
/*   Updated: 2022/11/07 06:11:07 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*chdst;
	const char	*chsrc;

	chdst = (char *)dst;
	chsrc = (const char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		chdst[i] = chsrc[i];
		i++;
	}
	return (dst);
}
