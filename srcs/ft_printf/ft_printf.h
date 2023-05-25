/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacharai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:36:45 by sacharai          #+#    #+#             */
/*   Updated: 2023/02/06 03:37:57 by sacharai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_putnbr(int nb, int *pos);
void	ft_putunsigned(unsigned int nb, int *pos);
void	ft_putptr(void *ptr, int *pos);
void	ft_putx(unsigned long int ptr, char x, int *len);
int		ft_printf(const char *format, ...);
void	ft_putstr(char *str, int *pos);
void	ft_putchar(char c, int *pos);

#endif
