/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:49:48 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 14:56:29 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	int_helper(long int n, t_hint *loco)
{
	int_helper_1(loco);
	if (n < 0)
	{
		if (loco->type[0] == '.' && loco->count++ && write(1, "-", 1))
			while (loco->width-- && loco->count++)
				write(1, "0", 1);
		else if (loco->type[2] == '.' && loco->widthx > 0)
			int_helper_2(loco);
		else if (loco->type[0] == '0' && loco->type[2] == '.')
			int_helper_3(loco);
		else if (loco->type[0] == '0')
			int_helper_4(loco);
	}
	else if (loco->type[0] == 'w' && loco->widthx > 0)
		while (loco->widthx-- && loco->count++)
			write(1, "0", 1);
	else if (loco->type[0] == '-' && loco->type[2] == '.')
		while (loco->widthx-- && loco->count++)
			write(1, "0", 1);
	else if (loco->type[0] == '0' && loco->type[2] == '.')
		int_helper_5(loco);
	else
		while (loco->width-- && loco->count++)
			write(1, "0", 1);
}

void	int_helper_one(t_hint *loco)
{
	if (loco->type[0] == '-')
	{
		while (loco->width--)
		{
			loco->count++;
			write(1, " ", 1);
		}
	}
	else if (loco->type[1] == '-')
	{
		while (loco->widthx--)
		{
			loco->count++;
			write(1, " ", 1);
		}
	}
}

void	int_helper_three(long int n, t_hint *loco)
{
	if (loco->type[0] == '-')
	{
		if (n < 0)
			while (loco->width-- && loco->count++)
				write(1, " ", 1);
		else
		{
			if (loco->width > 0 && n >= 0)
				while (loco->width-- && loco->count++)
					write(1, " ", 1);
			else if (loco->width > 0 && n < 0)
			{
				loco->width--;
				while (loco->width-- && loco->count++)
					write(1, " ", 1);
			}
		}
	}
	else if (loco->type[1] == '-')
	{
		loco->widthx--;
		while (loco->widthx-- && loco->count++)
			write(1, " ", 1);
	}
}

void	int_helper_four(long int n, int num, t_hint *loco)
{
	if (loco->type[0] == '-' && loco->type[2] == '.' && n >= 0)
		int_helper_four_2(num, loco);
	else if (loco->type[0] == '-' && loco->type[2] == '.' && n < 0)
		int_helper_four_3(num, loco);
	else if (loco->type[0] == 'w' && loco->type[2] == '.')
		int_helper_four_1(n, num, loco);
	else if (loco->type[2] == '.' && loco->type[0] == '-' && n != 0)
		loco->width = (loco->width - num) - (loco->widthx - num);
	else if (loco->type[2] == '.' && loco->type[0] == '-' && n == 0)
		loco->width = (loco->width - num) - (loco->widthx - num) + 1;
	else if (n < 0 && loco->type[0] == '.')
		loco->width -= num - 1;
	else if ((n < 0 && loco->type[0] == '0'))
		int_helper_four_4(num, loco);
	else if (loco->type[0] == '0' && loco->type[2] == '.')
		int_helper_four_5(num, loco);
	else
		loco->width -= num;
	int_helper_four_6(n, num, loco);
}

void	int_helper_five(long int n, t_hint *loco)
{
	if (loco->type[0] == ' ' && n >= 0 && loco->count++)
		write (1, " ", 1);
	else if (loco->type[0] == '+' && n >= 0 && loco->count++)
		write (1, "+", 1);
}
