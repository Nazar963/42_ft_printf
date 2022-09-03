/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:07:57 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 21:09:17 by naal-jen         ###   ########.fr       */
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
	if ((str[i] == '.' || str[i] == '-') && ft_isdigit(str[i + 1]) == 1)
		width_two(str, loco, &i);
	else if (str[i] == '.' && ft_isdigit(str[i + 1]) == 0)
	{
		loco->type[0] = 'd';
		loco->width = 0;
		i++;
	}
	return (i);
}

int	left_process(const char *str, t_hint *loco, int i)
{
	loco->type[0] = '-';
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
	i++;
	width_three(str, loco, &i);
	i++;
	return (i);
}

static int	me_dot(const char *str, t_hint *loco, int *i)
{
	loco->type[0] = '.';
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

int	leading_process(const char *str, t_hint *loco, int i)
{
	if (str[i + 1] == '#')
	{
		loco->type[2] = 'm';
		i++;
	}
	if (str[i] == '.')
	{
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
	else if (str[i] == '-')
		i = left_process(str, loco, i);
	return (i);
}
