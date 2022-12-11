/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:37:39 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/11 10:49:18 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int	width_process_1(const char *str, t_hint *loco, int i)
{
	loco->type[0] = 'd';
	if (str[i + 1] == 's')
		loco->widthx = loco->width;
	loco->width = 0;
	i++;
	return (i);
}

int	left_process_1(const char *str, t_hint *loco, int i)
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
	return (i);
}

int	*me_dot_1(const char *str, t_hint *loco, int *i)
{
	(*i)++;
	if (ft_isdigit(str[*i + 1]) == 1)
		(*i)++;
	loco->width += str[*i] - '0';
	if (loco->width < 6)
		loco->width = 0;
	(*i)++;
	return (i);
}

void	width_percent(const char *str, t_hint *loco, int *i)
{
	if (loco->type[0] == 'w')
	{
		while (loco->width--)
			write(1, " ", 1);
	}
	ft_putchar_fd(str[*i], 1);
}
