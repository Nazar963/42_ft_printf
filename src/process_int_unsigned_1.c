/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int_unsigned_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:30:12 by naal-jen          #+#    #+#             */
/*   Updated: 2025/05/10 19:51:56 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	number_unsigned_else(unsigned n, t_hint *loco)
{
	loco->width = 0;
	if (loco->widthx > 0 && n > 0)
		loco->widthx -= count_digits(n);
	else if (loco->widthx > 0)
		loco->widthx -= count_digits(n) - 1;
	if (loco->widthx < 0)
		loco->widthx = 0;
}

void	number_1(long int n, t_hint *loco)
{
	if (loco->width > 0 && loco->width >= count_digits(n))
		int_helper_four(n, count_digits(n), loco);
	else
	{
		loco->width = 0;
		if (loco->widthx > 0 && n > 0)
			loco->widthx -= count_digits(n);
		else if (loco->widthx > 0 && n < 0)
			loco->widthx -= count_digits(n) - 1;
		if (loco->widthx < 0)
			loco->widthx = 0;
	}
}

void	ifhex_1(unsigned int number, int length, t_hint *loco)
{
	if (loco->width > 0 && loco->width > length)
	{
		if (loco->widthx > length)
			loco->width -= loco->widthx;
		else
			loco->width -= length;
	}
	else
		loco->width = 0;
	if (loco->widthx > 0)
	{
		loco->widthx -= length;
		if (loco->widthx < 0)
			loco->widthx = 0;
	}
	else if (loco->type[2] == '.' && loco->widthx == 0 && loco->type[1] != 'n'
		&& number == 0)
	{
		loco->type[1] = 'y';
		loco->width++;
	}
}

void	str_six(char *string, t_hint *loco)
{
	loco->count += loco->width;
	while (loco->width--)
		write(1, " ", 1);
	ft_putstr_fd(string, 1);
}

void	width_seven(const char *str, t_hint *loco, int *i)
{
	loco->type[2] = '.';
	if (ft_isdigit(str[(*i) + 2]) == 1)
	{
		(*i)++;
		while (ft_isdigit(str[(*i)]) == 1)
		{
			loco->widthx += str[(*i)] - '0';
			if (ft_isdigit(str[(*i) + 1]) == 1)
				loco->widthx *= 10;
			(*i)++;
		}
		(*i)--;
	}
	else if (ft_isdigit(str[(*i) + 1]) == 1)
	{
		(*i)++;
		loco->widthx += str[(*i)] - '0';
	}
}
