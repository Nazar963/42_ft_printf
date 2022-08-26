/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_address_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:50:40 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/27 00:49:47 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char	*numberlength(unsigned long number, int *length)
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

static void	hex(t_hint *loco)
{
	if (loco->type[0] == 'w' && loco->width > 0)
	{
		while (loco->width--)
		{
			write(1, " ", 1);
			loco->count++;
		}
	}
	else if ((loco->type[0] == '0' || loco->type[0] == '.') && loco->width > 0)
	{
		while (loco->width--)
		{
			write(1, "0", 1);
			loco->count++;
		}
	}
}

static void	pointer(t_hint *loco)
{
	if (loco->type[0] == 'w' && loco->width > 0)
	{
		while (loco->width--)
		{
			loco->count++;
			write(1, " ", 1);
		}
		write(1, "0x", 2);
	}
	else if ((loco->type[0] == '0' || loco->type[0] == '.') && loco->width > 0)
	{
		write(1, "0x", 2);
		while (loco->width--)
		{
			write(1, "0", 1);
			loco->count++;
		}
	}
	
	else
		write(1, "0x", 2);
}

void	ifhex(unsigned int number, char cha, t_hint *loco)
{
	int		length;
	char	*string;

	length = 1;
	string = numberlength(number, &length);
	if (loco->width > 0 && loco->width > length)
		loco->width -= length;
	else
		loco->width = 0;
	while (--length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (cha == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (cha == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
	}
	loco->count += ft_strlen(string);
	hex(loco);
	ft_putstr_fd(string, 1);
	free(string);
	if (loco->type[0] == '-' && loco->width > 0)
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	}
}

void	ifpointer(uintptr_t number, t_hint *loco)
{
	int		length;
	char	*string;

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
	loco->count += ft_strlen(string) + 1;
	loco->width -= ft_strlen(string) + 2;
	pointer(loco);
	ft_putstr_fd(string, 1);
	free(string);
	if (loco->type[0] == '-' && loco->width > 0)
	{
		while (loco->width-- && loco->count++)
			write(1, " ", 1);
	}
}
