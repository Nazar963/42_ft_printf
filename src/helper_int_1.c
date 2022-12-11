/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_int_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:52:59 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 14:55:09 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	int_helper_3(t_hint *loco)
{
	if (loco->width > 0)
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	write(1, "-", 1);
	loco->count++;
}

void	int_helper_4(t_hint *loco)
{
	write(1, "-", 1);
	if (loco->width > 0 && loco->count++)
		while (loco->width-- && loco->count++)
			write(1, "0", 1);
	else
		loco->width--;
}

void	int_helper_5(t_hint *loco)
{
	while (loco->width-- && loco->count++)
		write(1, " ", 1);
	while (loco->widthx-- && loco->count++)
		write(1, "0", 1);
}

void	int_helper_four_1(long int n, int num, t_hint *loco)
{
	if (loco->widthx > num && n >= 0)
		loco->width -= loco->widthx;
	else if (loco->widthx < num && n < 0)
		loco->width -= num;
	else if (loco->widthx > num && n < 0)
		loco->width -= loco->widthx + 1;
	else if (loco->widthx < num && n >= 0 && loco->widthx != 0)
		loco->width -= num;
	else if (loco->widthx < num && n >= 0 && loco->widthx == 0)
		loco->width -= num;
	else if (loco->widthx == 0)
		loco->width -= loco->widthx;
	else if (loco->widthx == num && n < 0)
		loco->width -= loco->widthx + 1;
	else if (loco->widthx == num)
		loco->width -= loco->widthx;
	if (loco->widthx < num)
		loco->type[1] = '_';
	if (loco->widthx == 0 && n == 0)
	{
		loco->width++;
		loco->type[1] = 'y';
	}
}

void	int_helper_four_2(int num, t_hint *loco)
{
	if (loco->widthx > num)
		loco->width -= ((loco->widthx - num) + num);
	else if (loco->widthx < num)
		loco->width -= num;
	if (loco->widthx == 0)
	{
		loco->type[1] = 'y';
		loco->width++;
	}
}
