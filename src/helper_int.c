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
	{
		loco->count++;
		write (1, "+", 1);
	}
	if (loco->type[2] == '+' && loco->type[1] == '-')
	{
		loco->count++;
		write (1, "+", 1);
	}
	if (loco->type[2] == '+' && loco->type[1] == '0'
		&& loco->processed != 1 && loco->width--)
	{
		loco->count++;
		write (1, "+", 1);
	}
	if (n < 0)
	{
		if (loco->type[0] == '.' && loco->count++ && write(1, "-", 1))
		{
			while (loco->width--)
			{
				loco->count++;
				write(1, "0", 1);
			}
		}
		else if (loco->type[2] == '.' && loco->widthx > 0)
		{
			if (loco->type[0] == '0' && loco->width > 0)
			{
				while (loco->width--)
				{
					loco->count++;
					write(1, " ", 1);
				}
			}
			write(1, "-", 1);
			loco->count++;
			while (loco->widthx--)
			{
				loco->count++;
				write(1, "0", 1);
			}
		}
		else if (loco->type[0] == '0' && loco->type[2] == '.')
		{
			if (loco->width > 0)
			{
				while (loco->width--)
				{
					loco->count++;
					write(1, " ", 1);
				}
			}
			write(1, "-", 1);
			loco->count++;

		}
		else if (loco->type[0] == '0')
		{
			write(1, "-", 1);
			if (loco->width > 0)
			{
				loco->count++;
				while (loco->width--)
				{
					loco->count++;
					write(1, "0", 1);
				}
			}
			else
				loco->width--;
		}
	}
	else if (loco->type[0] == 'w' && loco->widthx > 0)
	{
		while (loco->widthx--)
		{
			loco->count++;
			write(1, "0", 1);
		}
	}
	else if (loco->type[0] == '-' && loco->type[2] == '.')
	{
		while (loco->widthx--)
		{
			loco->count++;
			write(1, "0", 1);
		}
	}
	else if (loco->type[0] == '0' && loco->type[2] == '.')
	{
		while (loco->width--)
		{
			loco->count++;
			write(1, " ", 1);
		}
		while (loco->widthx--)
		{
			loco->count++;
			write(1, "0", 1);
		}

	}
	else
	{
		while (loco->width--)
		{
			loco->count++;
			write(1, "0", 1);
		}
	}
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
		{
			while (loco->width--)
			{
				loco->count++;
				write(1, " ", 1);
			}
		}
		else
		{
			if (loco->width > 0 && n >= 0)
			{
				while (loco->width--)
				{
					loco->count++;
					write(1, " ", 1);
				}
			}
			else if (loco->width > 0 && n < 0)
			{
				loco->width--;
				while (loco->width--)
				{
					loco->count++;
					write(1, " ", 1);
				}
			}
		}
	}
	else if (loco->type[1] == '-')
	{
		loco->widthx--;
		while (loco->widthx--)
		{
			loco->count++;
			write(1, " ", 1);
		}
	}
}

void	int_helper_four(long int n, int num, t_hint *loco)
{
	if (loco->type[0] == '-' && loco->type[2] == '.' && n >= 0)
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
	else if (loco->type[0] == '-' && loco->type[2] == '.' && n < 0)
	{
		if (loco->widthx < num)
			loco->width -= num;
		else
			loco->width -= ((loco->widthx - num) + num) + 1;
	}
	else if (loco->type[0] == 'w' && loco->type[2] == '.')
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
	else if (loco->type[2] == '.' && loco->type[0] == '-' && n != 0)
		loco->width = (loco->width - num) - (loco->widthx - num);
	else if (loco->type[2] == '.' && loco->type[0] == '-' && n == 0)
		loco->width = (loco->width - num) - (loco->widthx - num) + 1;
	else if (n < 0 && loco->type[0] == '.')
		loco->width -= num - 1;
	else if ((n < 0 && loco->type[0] == '0'))
	{
		if (loco->widthx > num)
			loco->width -= loco->widthx + 1;
		else if (loco->type[2] == '.' && loco->widthx >= num)
			loco->width -= num + 1; // here
		else
			loco->width -= num; // here
		if (loco->width < 0)
			loco->width  = 0;
	}
	else if (loco->type[0] == '0' && loco->type[2] == '.')
	{
		if (loco->widthx >= num)
			loco->width -= loco->widthx;
		else if (loco->width > num && loco->widthx < num)
			loco->width -= num;
		if (loco->width < 0)
			loco->width = 0;
	}
	else
		loco->width -= num;
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

void	int_helper_five(long int n, t_hint *loco)
{
	if (loco->type[0] == ' ' && n >= 0 && loco->count++)
		write (1, " ", 1);
	else if (loco->type[0] == '+' && n >= 0 && loco->count++)
		write (1, "+", 1);
}