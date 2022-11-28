/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:37:42 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 15:35:18 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

void	me_char(va_list args, t_hint *loco)
{
	char	character;

	character = va_arg(args, int);
	if ((loco->type[0] == 'w' || loco->type[0] == '0') && loco->width > 0)
	{
		loco->count += loco->width - 1;
		while (--loco->width)
			write(1, " ", 1);
		ft_putchar_fd(character, 1);
	}
	else if (loco->type[0] == '-' && loco->width > 0)
	{
		loco->count += loco->width - 1;
		ft_putchar_fd(character, 1);
		while (--loco->width)
			write(1, " ", 1);
	}
	else
	{
		ft_putchar_fd(character, 1);
	}
}

static void	me_dot_stringo(char *string, t_hint *loco)
{
	size_t	num;
	size_t	wido;

	num = 0;
	wido = 0;
	if (loco->width == 0 && loco->widthx == 0) // modified the second con
	{
		loco->type[0] = 'a';
		return ;
	}
	else
	{
		if (loco->widthx > 0)
		{
			if ((loco->type[0] == 'w' || loco->type[0] == '0')
				&& loco->width > 0)
				str_one(wido, string, loco);
			str_two(num, string, loco);
			loco->type[0] = 'h';
		}
		else if (loco->widthx == 0 && loco->type[1] == 'o')
		{
			loco->type[0] = 'h';
			loco->type[2] = '.';
		}
		else
			str_three(num, string, loco);
	}
}

void	stringo(char *string, t_hint *loco)
{
	if (loco->type[0] == ' ')
		return ;
	if (loco->type[0] == 'd' && loco->width == 0)
	{
		if (loco->widthx > 0)
		{
			while (--loco->widthx)
				ft_putchar_fd(' ', 1);
		}
		string = 0;
		string = (char *)malloc(3 * sizeof(*string));
		string[0] = ' ';
		string[1] = '\0';
		loco->count += ft_strlen(string);
		ft_putstr_fd(string, 1);
		free (string);
		return ;
	}
	if ((loco->type[0] == '.' || loco->type[2] == '.') && string != NULL)
		me_dot_stringo(string, loco);
	if (loco->type[0] == 'a')
		return ;
	if (string == NULL)
	{
		if (loco->type[0] == '.' || loco->type[2] == '.')
		{
			string = "(null)";
			me_dot_stringo(string, loco);
		}
		if (loco->type[0] == 'a')
			return ;
		if (loco->type[0] == '.' && loco->width <= 5 && loco->width > 0)
			return ;
		else if (loco->type[0] == '.' && loco->width == 0)
			exit(0);
		else if (loco->type[2] == '.' && loco->type[1] == 'o')
		{
			while (loco->width--)
				ft_putchar_fd(' ', 1);
			return ;
		}
		else if (loco->type[2] == '.' && loco->type[0] == 'w' && loco->widthx)
		{
			while (loco->width--)
				ft_putchar_fd(' ', 1);
			return ;
		}
		else if (loco->type[2] == '.' && loco->type[0] == '-')
		{
			while (loco->width--)
				ft_putchar_fd(' ', 1);
			return ;
		}
		else
			string = "(null)";
	}
	str_four(string, loco);
}
