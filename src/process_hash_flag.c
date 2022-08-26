/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hash_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:04:25 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/25 16:59:59 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static void	sono_x(va_list args, t_hint *loco)
{
	unsigned int	numero;

	numero = va_arg(args, unsigned int);
	if (numero != 0)
	{
		write(1, "0x", 2);
		loco->count += 2;
	}
	ifhex(numero, 'x', loco);
}

static void	sono_big_x(va_list args, t_hint *loco)
{
	unsigned int	numero;

	numero = va_arg(args, unsigned int);
	if (numero != 0)
	{
		write(1, "0X", 2);
		loco->count += 2;
	}
	ifhex(numero, 'X', loco);
}

static void	sono_o(va_list args, t_hint *loco)
{
	unsigned int	numero;

	numero = va_arg(args, unsigned int);
	if (numero != 0)
	{
		write(1, "0", 1);
		loco->count += 1;
	}
	process_octal(numero, loco);
}

void	process_hash_flag(va_list args, t_hint *loco)
{
	if (loco->type[1] == 'x')
		sono_x(args, loco);
	else if (loco->type[1] == 'X')
		sono_big_x(args, loco);
	else if (loco->type[1] == 'o')
		sono_o(args, loco);
	else
		loco->inc -= 1;
}
