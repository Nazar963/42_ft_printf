/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_address_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:08:13 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 21:10:43 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	pointer_helper(t_hint *loco, char cha)
{
	write(1, "0", 1);
	write(1, &cha, 1);
	if (loco->type[0] == '.' && loco->type[2] == 'p')
	{
		loco->width += 2;
		while (loco->width-- && loco->count++)
			write(1, "0", 1);
	}
	else
	{
		while (loco->width-- && loco->count++)
			write(1, "0", 1);
	}
}

void	me_dot_number(t_hint *loco)
{
	if (loco->width == 0)
	{
		loco->type[0] = 'a';
		return ;
	}
}

void	ifhex_helper(char cha, t_hint *loco)
{
	if (loco->type[2] == 'm')
	{
		loco->width -= 2;
		loco->count += 2;
		pointer(loco, cha);
	}
	else if (loco->type[2] == 'q')
	{
		if (loco->widthx > 0)
		{
			loco->widthx -= 2;
			loco->count += 2;
		}
		else
			loco->count += 2;
		pointer(loco, cha);
	}
	else
		hex(loco);
}

void	ifhex_helper_two(t_hint *loco)
{
	if ((loco->type[0] == '-' || loco->type[1] == '-')
		&& (loco->width > 0 || loco->widthx > 0))
	{
		if (loco->type[0] == '-')
		{
			while (loco->width-- && loco->count++)
				write(1, " ", 1);
		}
		else if (loco->type[1] == '-')
		{
			while (loco->widthx-- && loco->count++)
				write(1, " ", 1);
		}
	}
}

void	ifhex_t(unsigned int number, char *string, int length, char cha)
{
	while (--length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (cha == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (cha == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
	}
}
