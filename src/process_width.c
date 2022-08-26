/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:07:57 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 18:09:06 by naal-jen         ###   ########.fr       */
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
	{
		while (ft_isdigit(str[i]) == 1)
		{
			loco->width += str[i] - '0';
			if (ft_isdigit(str[i + 1]) == 1)
				loco->width *= 10;
			i++;
		}
		i--;
	}
	else
		loco->width += str[i] - '0';
	i++;
	return (i);
}

int	left_process(const char *str, t_hint *loco, int i)
{
	loco->type[0] = '-';
	i++;
	if (ft_isdigit(str[i + 1]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
		{
			loco->width += str[i] - '0';
			if (ft_isdigit(str[i + 1]) == 1)
				loco->width *= 10;
			i++;
		}
		i--;
	}
	else
		loco->width += str[i] - '0';
	i++;
	return (i);
}

int	leading_process(const char *str, t_hint *loco, int i)
{
	loco->type[0] = '0';
	if (ft_isdigit(str[i + 1]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
		{
			loco->width += str[i] - '0';
			if (ft_isdigit(str[i + 1]) == 1)
				loco->width *= 10;
			i++;
		}
		i--;
	}
	else
		loco->width += str[i] - '0';
	i++;
	return (i);
}
