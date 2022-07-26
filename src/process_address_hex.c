/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_address_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:50:40 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 10:44:54 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

char	*numberlength(unsigned long number, int *length)
{
	char	*string;

	while (number >= 16)
	{
		number = number / 16;
		*length += 1;
	}
	string = (char *)malloc((*length + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[*length] = '\0';
	return (string);
}

void	hex(t_hint *loco)
{
	if (loco->type[0] == 'w' && loco->width > 0)
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	}
	else if ((loco->type[0] == '0' || loco->type[0] == '.')
		&& loco->width > 0 && loco->type[2] != '.')
	{
		while (loco->width-- && loco->count++)
			write(1, "0", 1);
	}
	else if (loco->type[0] == '0' && loco->width > 0 && loco->type[2] == '.')
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	}
	if (loco->type[2] == '.' && loco->widthx > 0)
	{
		while (loco->widthx-- && loco->count++)
			write(1, "0", 1);
	}
}

void	pointer(t_hint *loco, char cha)
{
	if (loco->type[0] == 'w' && loco->width > 0)
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
		write(1, "0", 1);
		write(1, &cha, 1);
	}
	else if ((loco->type[0] == '0' || loco->type[0] == '.') && loco->width > 0)
		pointer_helper(loco, cha);
	else if (loco->type[0] == ' ' && loco->count++)
	{
		write(1, " 0", 2);
		write(1, &cha, 1);
	}
	else if (loco->type[0] == '+' && loco->count++)
	{
		write(1, "+0", 2);
		write(1, &cha, 1);
	}
	else
	{
		write(1, "0", 1);
		write(1, &cha, 1);
	}
}

void	ifhex(unsigned int number, char cha, t_hint *loco)
{
	int		length;
	char	*string;

	length = 1;
	string = numberlength(number, &length);
	if (loco->type[0] == '.' && number == 0)
		me_dot_number(loco);
	if (loco->type[0] == 'a')
	{
		free (string);
		return ;
	}
	ifhex_1(number, length, loco);
	ifhex_t(number, string, length, cha);
	ifhex_helper(cha, loco);
	if (loco->type[1] != 'y')
	{
		loco->count += ft_strlen(string);
		ft_putstr_fd(string, 1);
	}
	free(string);
	ifhex_helper_two(loco);
}

void	ifpointer(uintptr_t number, t_hint *loco)
{
	int		length;
	char	*string;

	if (number == 0)
	{
		length = 6;
		string = numberlength(number, &length);
		ifp_help_one(string);
		ifp_help(loco, ft_strlen(string));
	}
	else
	{
		length = 1;
		string = numberlength(number, &length);
		while (--length >= 0)
		{
			if (number % 16 < 10)
				string[length] = '0' + (number % 16);
			else
				string[length] = 'a' + (number % 16) - 10;
			number = number / 16;
		}
		ifp_help_two(loco, ft_strlen(string));
	}
	ifp_help_four(loco, string);
}
