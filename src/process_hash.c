/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:41:19 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 15:18:45 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

int	me_space(const char *str, t_hint *loco, int i)
{
	loco->type[0] = ' ';
	i++;
	if (str[i] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	if (str[i] == '+')
	{
		loco->type[0] = '+';
		while (str[i] != 'i')
			i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		i++;
	}
	if (str[i] == 's')
		fail();
	return (i);
}

int	me_plus(const char *str, t_hint *loco, int i)
{
	loco->type[0] = '+';
	i++;
	if (str[i] == '+')
	{
		while (str[i] == '+')
			i++;
	}
	if (str[i] == ' ')
	{
		while (str[i] != 'i')
			i++;
	}
	if (str[i] == '0')
	{
		loco->type[2] = '+';
		i = leading_process(str, loco, i);
	}
	return (i);
}

int	me_hash(va_list args, t_hint *loco, const char *str, int i)
{
	int	modf;

	modf = 0;
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
	else if (str[i] == '0' || str[i] == '-')
	{
		modf = hash_five(loco, str, &i, &modf);
		if (modf > 0)
			return (modf);
	}
	return (i);
}
