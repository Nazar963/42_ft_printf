/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:41:19 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 21:17:01 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int	me_space(t_hint *loco, int i)
{
	loco->type[0] = ' ';
	i++;
	return (i);
}

int	me_plus(t_hint *loco, int i)
{
	loco->type[0] = '+';
	i++;
	return (i);
}

int	me_hash(va_list args, t_hint *loco, const char *str, int i)
{
	loco->type[0] = '#';
	if (str[i] == '#')
	{
		while (str[i] == '#')
			i++;
	}
	if (str[i] == 'x' || str[i] == 'X' || str[i] == 'o')
	{
		loco->type[1] = str[i];
		process_hash_flag(args, loco);
		loco->processed = 1;
	}
	return (i);
}
