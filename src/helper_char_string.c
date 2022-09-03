/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_char_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:26:05 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 17:17:20 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	str_one(size_t wido, char *string, t_hint *loco)
{
	wido = loco->widthx;
	if (wido < ft_strlen(string))
		loco->width -= loco->widthx;
	else
		loco->width -= ft_strlen(string);
	loco->count += loco->width;
	while (loco->width--)
		write(1, " ", 1);
}

void	str_two(size_t num, char *string, t_hint *loco)
{
	while (loco->widthx && num < ft_strlen(string))
	{
		ft_putchar_fd(string[num], 1);
		num++;
		loco->widthx--;
		loco->count++;
	}
}

void	str_three(size_t num, char *string, t_hint *loco)
{
	while (loco->width && num < ft_strlen(string))
	{
		ft_putchar_fd(string[num], 1);
		num++;
		loco->width--;
		loco->count++;
	}
	loco->type[0] = 'h';
}

void	str_four(char *string, t_hint *loco)
{
	if (loco->type[0] != 'h')
		loco->count += ft_strlen(string);
	loco->width -= ft_strlen(string);
	if ((loco->type[0] == 'w' || loco->type[0] == '0') && loco->width > 0)
	{
		loco->count += loco->width;
		while (loco->width--)
			write(1, " ", 1);
		ft_putstr_fd(string, 1);
	}
	else if (loco->type[0] == '-' && loco->width > 0)
	{
		loco->count += loco->width;
		ft_putstr_fd(string, 1);
		while (loco->width--)
			write(1, " ", 1);
	}
	else if (loco->type[0] != 'h')
		ft_putstr_fd(string, 1);
}
