/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:18:53 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 11:02:19 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	width_one(const char *str, t_hint *loco, int *i)
{
	while (ft_isdigit(str[(*i)]) == 1)
	{
		loco->width += str[(*i)] - '0';
		if (ft_isdigit(str[(*i) + 1]) == 1)
			loco->width *= 10;
		(*i)++;
	}
	(*i)--;
}

void	width_two(const char *str, t_hint *loco, int *i)
{
	if (str[(*i) + 1] == '0' && (str[(*i) + 2] == 'x' || str[(*i) + 2] == 'X')
		&& va_arg(loco->args2, int) != 0)
	{
		loco->type[1] = 'n';
		(*i)++;
		(*i)++;
	}
	else if (ft_isdigit(str[(*i) + 1]) == 1)
		width_six(str, loco, i);
	else
	{
		(*i)++;
		while (ft_isdigit(str[(*i)]) == 1)
			(*i)++;
		if (str[(*i)] == '%')
			loco->type[0] = 0;
	}
}

void	width_three(const char *str, t_hint *loco, int *i)
{
	if (ft_isdigit(str[(*i) + 1]) == 1)
	{
		while (ft_isdigit(str[(*i)]) == 1)
		{
			loco->width += str[(*i)] - '0';
			if (ft_isdigit(str[(*i) + 1]) == 1)
				loco->width *= 10;
			(*i)++;
		}
		(*i)--;
	}
	else
		loco->width += str[(*i)] - '0';
}

void	width_four(const char *str, t_hint *loco, int *i)
{
	loco->type[0] = '0';
	if (str[(*i) + 1] == '+')
	{
		loco->type[2] = '+';
		(*i)++;
	}
	if (ft_isdigit(str[(*i) + 2]) == 1)
	{
		(*i)++;
		while (ft_isdigit(str[(*i)]) == 1)
		{
			loco->width += str[(*i)] - '0';
			if (ft_isdigit(str[(*i) + 1]) == 1)
				loco->width *= 10;
			(*i)++;
		}
		(*i)--;
	}
	else if (ft_isdigit(str[(*i) + 1]) == 1)
	{
		(*i)++;
		loco->width += str[(*i)] - '0';
	}
	(*i)++;
}

void	width_five(const char *str, t_hint *loco, int *i)
{
	if (str[(*i) + 2] == 'X' && loco->type[0] != '0')
	{
		loco->width = 0;
		loco->width += str[(*i) + 1] - '0';
		loco->type[0] = '.';
		(*i)++;
	}
	else
		width_seven(str, loco, i);
	(*i)++;
	while (ft_isdigit(str[(*i)]) == 1)
		(*i)++;
	if (str[(*i)] == '%')
		loco->type[0] = '0';
}
