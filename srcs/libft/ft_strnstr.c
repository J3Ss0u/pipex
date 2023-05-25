/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 08:28:25 by sacharai          #+#    #+#             */
/*   Updated: 2022/11/07 06:18:34 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	ln;
	char	*str;

	i = 0;
	j = 0;
	ln = ft_strlen(n);
	str = (char *)h;
	if (ln == 0)
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == n[j] && i + j < len && n[j] && str[i + j])
			j++;
		if (j == ln)
			return (str + i);
		i++;
	}
	return (0);
}
