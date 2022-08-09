/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:05:15 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/09 18:10:24 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"
#include <stdio.h>

static t_hint	*my_struct(void)
{
	t_hint	*loco;

	loco = (t_hint *)malloc(sizeof(t_hint));
	if (!loco)
		return (NULL);
	loco->count = 1;
	return (loco);
}

static void	process_loco(const char *str, va_list args, t_hint *loco)
{
	if (*str == 'c' && loco->count++)
		ft_putchar_fd(va_arg(args, int), 1);
	if (*str == 's')
		stringo(va_arg(args, char *), loco);
	if (*str == 'p' && loco->count++)
		ifpointer(va_arg(args, uintptr_t), loco);
	if (*str == 'd' || *str == 'i')
		number(va_arg(args, int), loco);
	if (*str == 'u')
		number_unsigned(va_arg(args, unsigned int), loco);
	if (*str == 'x' || *str == 'X')
		ifhex(va_arg(args, unsigned int), *str, loco);
	if (*str == '%' && loco->count++)
		write (1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_hint	*loco;
	int		i;

	loco = my_struct();
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			loco->count++;
		}
		else if (str[i] == '%')
		{
			process_loco(&str[++i], args, loco);
		}
		i++;
	}
	i = loco->count - 1;
	va_end(args);
	free(loco);
	return (i);
}
