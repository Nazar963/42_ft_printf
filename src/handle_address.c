/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:50:40 by naal-jen          #+#    #+#             */
/*   Updated: 2022/07/28 20:04:41 by naal-jen         ###   ########.fr       */
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

void	ifhex(unsigned int number, char character, t_hint *loco)
{
	int				length;
	char			*string;

	length = 1;
	string = numberlength(number, &length);
	loco->count += length;
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else if (character == 'x')
			string[length] = 'a' - 10 + (number % 16);
		else if (character == 'X')
			string[length] = 'A' - 10 + (number % 16);
		number = number / 16;
		length--;
	}
	ft_putstr_fd(string, 1);
	free(string);
}

void	ifpointer(uintptr_t number, t_hint *loco)
{
	int		length;
	char	*string;

	length = 1;
	write(1, "0x", 2);
	string = numberlength(number, &length);
	loco->count += length + 1;
	length--;
	while (length >= 0)
	{
		if (number % 16 < 10)
			string[length] = '0' + (number % 16);
		else
			string[length] = 'a' + (number % 16) - 10;
		number = number / 16;
		length--;
	}
	ft_putstr_fd(string, 1);
	free(string);
}
