/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:07:57 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/29 20:12:47 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

void	width_percent(const char *str, t_hint *loco, int *i)
{
	if (loco->type[0] == 'w')
	{
		while (loco->width--)
			write(1, " ", 1);
	}
	ft_putchar_fd(str[*i], 1);
}

int	width_process(const char *str, t_hint *loco, int i)
{
	loco->type[0] = 'w';
	if (ft_isdigit(str[i + 1]) == 1)
		width_one(str, loco, &i);
	else
		loco->width += str[i] - '0';
	i++;
	if ((str[i] == '.' || str[i] == '-') && ft_isdigit(str[i + 1]))
		width_two(str, loco, &i);
	else if (str[i] == '.' && ft_isdigit(str[i + 1]) == 0 && str[i + 1] == 's')
	{
		loco->type[0] = 'd';
		if (str[i + 1] == 's')
			loco->widthx = loco->width;
		loco->width = 0;
		i++;
	}
	else if (str[i] == '.' && (str[i + 1] == 'x' || str[i + 1] == 'X') && va_arg(loco->args2, int) != 0)
	{
		loco->type[1] = 'n';
		i++;
	}
	else if (str[i] == '.' && ft_isdigit(str[i + 1]) == 0)
	{
		loco->type[2] = '.';
		i++;
	}
	return (i);
}

int	left_process(const char *str, t_hint *loco, int i)
{
	loco->type[0] = '-';
	if (str[i + 1] == '-')
	{
		while (str[i] == '-')
			i++;
		i--;	
	}
	if (str[i + 1] == '#')
	{
		if (str [i + 2] == '.')
		{
			i += 2;
			i = leading_process(str, loco, i);
			loco->type[2] = 'q';
			return (i);
		}
		else
		{
			loco->type[2] = 'm';
			i++;
		}
	}
	if (ft_isdigit(str[i + 1]) == 1)
	{
		i++;
		width_three(str, loco, &i);
	}
	i++;
	if (str[i] == '.')
	{
		// loco->widthx = loco->width;
		i = leading_process(str, loco, i);
		// loco->width = loco->widthx;
		// loco->type[0] = '-'; 
	}
	return (i);
}

static int	me_dot(const char *str, t_hint *loco, int *i)
{
	loco->type[0] = '.';
	if (str[*i + 1] == '0' && va_arg(loco->args2, char *) == NULL)
	{
		(*i)++;
		if (ft_isdigit(str[*i + 1]) == 1)
			(*i)++;
		loco->width += str[*i] - '0';
		if (loco->width < 6)
			loco->width = 0;
		// while (ft_isdigit(str[*i + 1]) == 1)
		// 	(*i)++;
		(*i)++;
		return (*i);
	}
	if (ft_isdigit(str[*i + 2]) == 1)
	{
		(*i)++;
		while (ft_isdigit(str[*i]) == 1)
		{
			loco->width += str[*i] - '0';
			if (ft_isdigit(str[(*i) + 1]) == 1)
				loco->width *= 10;
			(*i)++;
		}
		(*i)--;
	}
	else if (ft_isdigit(str[*i + 1]) == 1)
	{
		(*i)++;
		loco->width += str[*i] - '0';
	}
	(*i)++;
	return (*i);
}

static int	me_dot_second(const char *str, t_hint *loco, int *i)
{
	loco->type[2] = '.';
	if (ft_isdigit(str[*i + 2]) == 1)
	{
		(*i)++;
		while (ft_isdigit(str[*i]) == 1)
		{
			loco->widthx += str[*i] - '0';
			if (ft_isdigit(str[(*i) + 1]) == 1)
				loco->widthx *= 10;
			(*i)++;
		}
		(*i)--;
	}
	else if (ft_isdigit(str[*i + 1]) == 1)
	{
		(*i)++;
		loco->widthx += str[*i] - '0';
	}
	else
		loco->type[1] = 'o';
	(*i)++;
	return (*i);
}

int	leading_process(const char *str, t_hint *loco, int i)
{
	if (str[i + 1] == '#')
	{
		loco->type[2] = 'm';
		i++;
	}
	if (str[i] == '.')
	{
		if (loco->type[0] == '-')
			i = me_dot_second(str, loco, &i);
		else
			i = me_dot(str, loco, &i);
		return (i);
	}
	if (str[i + 1] == '.' && ft_isdigit(str[i + 2]) == 0)
	{
		i += 2;
		return (i);
	}
	width_four(str, loco, &i);
	if ((str[i] == '.') && ft_isdigit(str[i + 1]) == 1)
		width_five(str, loco, &i);
	else if ((str[i] == '.') && ft_isdigit(str[i + 1]) == 0)
	{
		loco->type[2] = '.';
		i++;
	}
	else if (str[i] == '-')
		i = left_process(str, loco, i);
	return (i);
}
