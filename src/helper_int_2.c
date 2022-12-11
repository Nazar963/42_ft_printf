/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_int_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:54:42 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 14:56:18 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	int_helper_four_3(int num, t_hint *loco)
{
	if (loco->widthx < num)
		loco->width -= num;
	else
		loco->width -= ((loco->widthx - num) + num) + 1;
}

void	int_helper_four_4(int num, t_hint *loco)
{
	if (loco->widthx > num)
		loco->width -= loco->widthx + 1;
	else if (loco->type[2] == '.' && loco->widthx >= num)
		loco->width -= num + 1;
	else
		loco->width -= num;
	if (loco->width < 0)
		loco->width = 0;
}

void	int_helper_four_5(int num, t_hint *loco)
{
	if (loco->widthx >= num)
		loco->width -= loco->widthx;
	else if (loco->width > num && loco->widthx < num)
		loco->width -= num;
	if (loco->width < 0)
		loco->width = 0;
}

void	int_helper_four_6(long int n, int num, t_hint *loco)
{
	if (loco->widthx > 0)
	{
		if (n < 0)
			loco->widthx = (loco->widthx + 1) - num;
		else
			loco->widthx -= num;
	}
	if (loco->widthx < 0)
		loco->widthx = 0;
}
