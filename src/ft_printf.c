/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:05:15 by naal-jen          #+#    #+#             */
/*   Updated: 2022/09/03 21:15:57 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"
#include <limits.h>

static int	*proc(const char *str, va_list args, t_hint *loco, int *i)
{
	if (str[*i] == '#')
		*i = me_hash(args, loco, str, ++(*i));
	if (str[*i] == 'c' && loco->count++ && loco->processed == 0)
		me_char(args, loco);
	else if (str[*i] == 's' && loco->processed == 0)
		stringo(va_arg(args, char *), loco);
	else if (str[*i] == 'p' && loco->count++ && loco->processed == 0)
		ifpointer(va_arg(args, uintptr_t), loco);
	else if ((str[*i] == 'd' || str[*i] == 'i') && loco->processed == 0)
		number(va_arg(args, int), loco);
	else if (str[*i] == 'u' && loco->processed == 0)
		number_unsigned(va_arg(args, unsigned int), loco);
	else if ((str[*i] == 'x' || str[*i] == 'X') && loco->processed == 0)
		ifhex(va_arg(args, unsigned int), str[*i], loco);
	else if (str[*i] == '%' && loco->count++ && loco->processed == 0)
		write (1, "%", 1);
	else if (str[*i] == '\0')
		return (i);
	else if (loco->processed == 0)
	{
		width_percent(str, loco, i);
		loco->count++;
	}
	loco->processed = 0;
	return (i);
}

static void	proc_f(const char *str, int *i, t_hint *loco)
{
	if (str[*i] == '0')
		*i = leading_process(str, loco, (*i));
	else if (str[*i] == '.')
		*i = leading_process(str, loco, (*i));
	else if ((str[(*i) - 1] == '%') && (str[*i] == ' '))
		*i = me_space(str, loco, (*i));
	else if (str[*i] == '+')
		*i = me_plus(str, loco, (*i));
	else if (ft_isdigit(str[*i]) == 1)
		*i = width_process(str, loco, (*i));
	else if (str[*i] == '-')
		*i = left_process(str, loco, (*i));
}

static void	general_process(const char *str, int *i, va_list args, t_hint *loco)
{
	while (str[*i])
	{
		if (str[*i] != '%' && loco->count++)
			ft_putchar_fd(str[*i], 1);
		else if (str[(*i)++] == '%')
		{
			proc_f(str, i, loco);
			proc(str, args, loco, i);
			if (loco->type[1] == 'n')
				return ;
			loco->width = 0;
			loco->widthx = 0;
			loco->type[0] = 0;
			if (str[*i] == '\0')
				return ;
		}
		(*i)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_hint	*loco;
	int		*i;
	int		result;

	result = 0;
	loco = my_struct();
	va_start(args, str);
	i = new_i();
	general_process(str, i, args, loco);
	result = loco->count - 1;
	va_end(args);
	free(loco);
	free(i);
	return (result);
}

// int	main(void)
// {
// 	// printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// printf("\n");
// 	// ft_printf(" %-9d %-10d %-11d %-12d %-13d %-14d %-15d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
// 	// printf("\n");

// 	// printf(" %.1s|", "");
// 	// printf("\n");
// 	// ft_printf(" %.1s|", "");
// 	// printf("\n");

// 	// // s_hidden = "hi low\0don't print me lol\0"

// 	printf("%.s", NULL);
// 	printf("\n");
// 	ft_printf("%.s", NULL);
// 	printf("\n");
// 	// printf("\n");

// 	// printf("%3.1s", NULL);
// 	// printf("\n");
// 	// ft_printf("%3.1s", NULL);
// 	// printf("\n");
// }