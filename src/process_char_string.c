/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 10:37:42 by naal-jen          #+#    #+#             */
/*   Updated: 2022/12/07 15:44:19 by naal-jen         ###   ########.fr       */
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

void	me_dot_str_1(char *string, t_hint *loco, size_t num, size_t wido)
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
	else if (loco->type[2] == '.' && loco->widthx == 0)
	{
		loco->type[1] = 'j';
		return ;
	}
	else
		str_three(num, string, loco);
}

void	me_dot_stringo(char *string, t_hint *loco)
{
	size_t	num;
	size_t	wido;

	num = 0;
	wido = 0;
	if (loco->width == 0 && loco->widthx == 0)
	{
		loco->type[0] = 'a';
		return ;
	}
	else
		me_dot_str_1(string, loco, num, wido);
}

void	stringo_1(char *string, t_hint *loco)
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
	loco->type[1] = '1';
}

void	stringo(char *string, t_hint *loco)
{
	if (loco->type[0] == ' ')
		return ;
	if (loco->type[0] == 'd' && loco->width == 0)
	{
		stringo_1(string, loco);
		if (loco->type[1] == '1')
			return ;
	}
	if ((loco->type[0] == '.' || loco->type[2] == '.') && string != NULL)
		me_dot_stringo(string, loco);
	if (loco->type[0] == 'a')
		return ;
	if (string == NULL && loco->type[2] != 'a')
	{
		handle_string_null(string, loco);
		if (loco->type[1] == '1')
			return ;
		string = stringo_3(string, loco);
		string = stringo_2(string, loco);
		if (loco->type[1] == '1')
			return ;
	}
	str_four(string, loco);
}
