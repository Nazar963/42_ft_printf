/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:37:42 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 17:24:00 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	me_char(va_list args, t_hint *loco)
{
	char	character;

	character = va_arg(args, int);
	if ((loco->type[0] == 'w' || loco->type[0] == '0') && loco->width > 0)
	{
		loco->count += loco->width - 1;
		while (--loco->width)
			write(1, " ", 1);
		ft_putchar_fd(character, 1);
	}
	else if (loco->type[0] == '-' && loco->width > 0)
	{
		loco->count += loco->width - 1;
		ft_putchar_fd(character, 1);
		while (--loco->width)
			write(1, " ", 1);
	}
	else
	{
		ft_putchar_fd(character, 1);
	}
}

void	stringo(char *string, t_hint *loco)
{
	if (string == NULL)
		string = "(null)";
	loco->count += ft_strlen(string);
	loco->width -= ft_strlen(string);
	if ((loco->type[0] == 'w' || loco->type[0] == '0') && loco->width > 0)
	{
		loco->count += loco->width;
		while (loco->width--)
			write(1, " ", 1);
		ft_putstr_fd(string, 1);
	}
	else if (loco->type[0] == '-' && loco->width > 0)
	{
		loco->count += loco->width;
		ft_putstr_fd(string, 1);
		while (loco->width--)
			write(1, " ", 1);
	}
	else
		ft_putstr_fd(string, 1);
}
