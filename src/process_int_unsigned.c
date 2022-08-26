/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:37:24 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 20:12:02 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

static int	count_digits(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	if (n < 0)
		i += 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_mod(unsigned int n)
{
	char		*ptr;
	int			i;

	i = count_digits(n);
	ptr = (char *)malloc((i + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ptr[i] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[--i] = n % 10 + '0';
		n = n / 10;
	}
	return (ptr);
}

static void	process_number_flag(t_hint *loco,long int n)
{
	if (loco->type[0] == 'w' && loco->width > 0)
	{
		while (loco->width--)
			write(1, " ", 1);
	}
	else if ((loco->type[0] == '0' || loco->type[0] == '.') && loco->width > 0)
	{
		if (n < 0)
		{
			write(1, "-", 1);
			loco->count++;
			while (loco->width--)
				write(1, "0", 1);
		}
		else
		{
			while (loco->width--)
				write(1, "0", 1);
		}
	}
	else if (loco->type[0] == '+' && n > 0)
		write (1, "+", 1);
	else if (loco->type[0] == ' ' && n > 0)
		write (1, " ", 1);
}

void	number_unsigned(unsigned n, t_hint *loco)
{
	char	*string;

	if (loco->width > 0 && loco->width > count_digits(n))
		loco->width -= count_digits(n);
	else
		loco->width = 0;
	loco->count += loco->width;
	process_number_flag(loco, n);
	string = ft_itoa_mod(n);
	loco->count += ft_strlen(string);
	ft_putstr_fd(string, 1);
	if (loco->type[0] == '-' && loco->width > 0)
	{
		while (loco->width--)
			write(1, " ", 1);
	}
	free (string);
}

void	number(long int n, t_hint *loco)
{
	char	*string;

	if (loco->width > 0 && loco->width > count_digits(n))
		loco->width -= count_digits(n);
	else
		loco->width = 0;
	loco->count += loco->width;
	process_number_flag(loco, n);
	if (loco->type[0] == '0' && n < 0 && loco->width  == -1)
	{
		n *= -1;
		string = ft_itoa(n);
	}
	else
		string = ft_itoa(n);
	loco->count += ft_strlen(string);
	ft_putstr_fd(string, 1);
	if (loco->type[0] == '-' && loco->width > 0)
	{
		while (loco->width--)
			write(1, " ", 1);
	}
	free (string);
}
