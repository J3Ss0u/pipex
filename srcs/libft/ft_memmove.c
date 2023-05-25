/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:00:02 by sacharai          #+#    #+#             */
/*   Updated: 2022/11/04 12:20:40 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*chdst;
	char	*chsrc;

	chdst = (char *)dst;
	chsrc = (char *)src;
	if (src < dst)
	{
		while (len--)
			chdst[len] = chsrc[len];
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
