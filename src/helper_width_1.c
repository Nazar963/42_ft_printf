/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_width_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:02:55 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 14:52:05 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	width_six(const char *str, t_hint *loco, int *i)
{
	loco->type[2] = '.';
	(*i)++;
	while (ft_isdigit(str[(*i)]) == 1)
	{
		loco->widthx += str[(*i)] - '0';
		if (ft_isdigit(str[(*i) + 1]) == 1)
			loco->widthx *= 10;
		(*i)++;
	}
	if (va_arg(loco->args2, char *) == NULL && str[(*i)] == 's')
	{
		if (loco->widthx < 6)
		{
			loco->widthx = 0;
			loco->type[2] = 'a';
		}
	}
}

char	*stringo_2(char *string, t_hint *loco)
{
	if (loco->type[0] == '.' && loco->width <= 5 && loco->width > 0)
		loco->type[1] = '1';
	else if (loco->type[0] == '.' && loco->width == 0)
		exit(0);
	else if (loco->type[2] == '.' && loco->type[1] == 'o')
	{
		while (loco->width--)
			ft_putchar_fd(' ', 1);
		loco->type[1] = '1';
	}
	else if (loco->type[2] == '.' && loco->type[0] == 'w' && loco->widthx)
	{
		while (loco->width--)
			ft_putchar_fd(' ', 1);
		loco->type[1] = '1';
	}
	else if (loco->type[2] == '.' && loco->type[0] == '-')
	{
		while (loco->width--)
			ft_putchar_fd(' ', 1);
		loco->type[1] = '1';
	}
	else
		string = "(null)";
	return (string);
}

char	*stringo_3(char *string, t_hint *loco)
{
	if (loco->type[0] == '.')
	{
		if (loco->width < 5 && loco->width > 0)
		{
			loco->type[1] = '1';
			return (0);
		}
		string = "(null)";
		me_dot_stringo(string, loco);
	}
	if (loco->type[2] == '.')
	{
		if (loco->widthx < 5 && loco->widthx > 0)
		{
			loco->type[1] = '1';
			return (0);
		}
		string = "(null)";
		me_dot_stringo(string, loco);
	}
	if (loco->type[0] == 'a' || loco->type[2] == 'a')
		loco->type[1] = '1';
	return (string);
}

void	int_helper_1(t_hint *loco)
{
	if (loco->type[2] == '+' && loco->type[0] == '0' && loco->width--
		&& loco->count++)
		write (1, "+", 1);
	if (loco->type[2] == '+' && loco->type[1] == '-' && loco->count++)
		write (1, "+", 1);
	if (loco->type[2] == '+' && loco->type[1] == '0'
		&& loco->processed != 1 && loco->width-- && loco->count++)
		write (1, "+", 1);
}

void	int_helper_2(t_hint *loco)
{
	if (loco->type[0] == '0' && loco->width > 0)
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	write(1, "-", 1);
	loco->count++;
	while (loco->widthx-- && loco->count++)
		write(1, "0", 1);
}
