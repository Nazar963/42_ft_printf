/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:52:59 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 17:17:26 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	ifp_help_one(char *string)
{
	string[0] = '(';
	string[1] = 'n';
	string[2] = 'i';
	string[3] = 'l';
	string[4] = ')';
	string[5] = '\0';
}

void	ifp_help(t_hint *loco, size_t num)
{
	loco->count += num - 1;
	loco->width -= num;
	if (loco->type[0] == 'w' && loco->width > 0)
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	}
}

void	ifp_help_two(t_hint *loco, size_t num)
{
	loco->count += num + 1;
	loco->width -= num + 2;
	loco->type[2] = 'p';
	pointer(loco, 'x');
}

void	ifp_help_four(t_hint *loco, char *string)
{
	ft_putstr_fd(string, 1);
	free(string);
	if (loco->type[0] == '-' && loco->width > 0)
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	}
}
