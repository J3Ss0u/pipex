/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:36:51 by sacharai          #+#    #+#             */
/*   Updated: 2022/11/13 06:03:34 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;
	size_t	ls1;

	if (!s1)
		return (NULL);
	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		ls1 = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]) != 0)
			i++;
		if (i == ls1)
			return (ft_strdup(""));
		while (s1[ls1 - 1] && ft_strchr(set, s1[ls1 - 1]) != 0 && ls1 > i)
			ls1--;
			str = (char *)malloc(sizeof(char) * (ls1 - i + 1));
		if (!str)
			return (NULL);
		if (str)
			ft_strlcpy (str, &s1[i], ls1 - i + 1);
	}
	return (str);
}
