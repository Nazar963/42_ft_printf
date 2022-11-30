/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 10:59:00 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/30 17:39:38 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	handle_string_null(char *string, t_hint *loco)
{
	loco->type[1] = '1';
	if (loco->type[0] == '-' && loco->width > 0 && loco->type[2] == '.')
	{
		loco->count += loco->width;
		while (loco->width--)
			write(1, " ", 1);
	}
}