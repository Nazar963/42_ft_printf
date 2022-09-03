/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:49:48 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 17:16:31 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	int_helper(long int n, t_hint *loco)
{
	if (loco->type[2] == '+' && loco->type[0] == '0' && loco->width--)
		write (1, "+", 1);
	if (loco->type[2] == '+' && loco->type[1] == '-')
		write (1, "+", 1);
	if (loco->type[2] == '+' && loco->type[1] == '0'
		&& loco->processed != 1 && loco->width--)
		write (1, "+", 1);
	if (n < 0)
	{
		if (loco->type[0] == '.' && loco->count++ && write(1, "-", 1))
		{
			while (loco->width--)
				write(1, "0", 1);
		}
		else
		{
			write(1, "-", 1);
			loco->width--;
			while (loco->width--)
				write(1, "0", 1);
		}
	}
	else
		while (loco->width--)
			write(1, "0", 1);
}

void	int_helper_one(t_hint *loco)
{
	if (loco->type[0] == '-')
	{
		while (loco->width--)
			write(1, " ", 1);
	}
	else if (loco->type[1] == '-')
	{
		while (loco->widthx--)
			write(1, " ", 1);
	}
}

void	int_helper_three(long int n, t_hint *loco)
{
	if (loco->type[0] == '-')
	{
		if (n < 0)
		{
			loco->count--;
			loco->width--;
			while (loco->width--)
				write(1, " ", 1);
		}
		else
		{
			while (loco->width--)
				write(1, " ", 1);
		}
	}
	else if (loco->type[1] == '-')
	{
		loco->widthx--;
		while (loco->widthx--)
			write(1, " ", 1);
	}
}

void	int_helper_four(long int n, int num, t_hint *loco)
{
	if (n < 0)
		loco->width -= num - 1;
	else
		loco->width -= num;
}

void	int_helper_five(long int n, t_hint *loco)
{
	if (loco->type[0] == ' ' && n >= 0 && loco->count++)
		write (1, " ", 1);
	else if (loco->type[0] == '+' && n >= 0 && loco->count++)
		write (1, "+", 1);
}
