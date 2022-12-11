/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:59:00 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 10:55:12 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	handle_string_null(char *string, t_hint *loco)
{
	if (loco->type[0] == '-' && loco->width > 0 && loco->type[2] == '.'
		&& loco->widthx < 6)
	{
		loco->type[1] = '1';
		loco->count += loco->width;
		while (loco->width--)
			write(1, " ", 1);
	}
	else if (loco->type[0] == '-' && loco->width > 0 && loco->type[2] == '.'
		&& loco->widthx >= 6)
	{
		string = "(null)";
		loco->type[1] = '1';
		loco->count += ft_strlen(string);
		loco->width -= ft_strlen(string);
		ft_putstr_fd(string, 1);
		if (loco->width > 0)
		{
			loco->count += loco->width;
			while (loco->width--)
				write(1, " ", 1);
		}
	}
}
