/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:05:15 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 23:59:03 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"
#include <stdio.h>
#include <string.h> // va_start va_arg va_copy va_end va_list
#include <limits.h> // va_start va_arg va_copy va_end va_list

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
	if ((str[*i] == '0') || (str[*i] == '.'))
		*i = leading_process(str, loco, (*i));
	else if ((str[(*i) - 1] == '%') && (str[*i] == ' '))
		*i = me_space(loco, (*i));
	else if (str[*i] == '+' && loco->count++)
		*i = me_plus(loco, (*i));
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
			loco->width = 0;
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
int	main(void)
{
	int	a = 5;
	printf("1\n");
	printf("=>%d\n", printf("% p", &a));
	ft_printf("=>%d\n\n", ft_printf("% p", &a));

	// printf("2\n");
	// printf("=>%d\n", printf(" %015u ", -177013));
	// ft_printf("=>%d\n\n", ft_printf(" %015u ", -177013));

	// printf("3\n");
	// printf("=>%d\n", printf(" %010% "));
	// ft_printf("=>%d\n\n", ft_printf(" %010% "));

	// printf("4\n");
	// printf("=>%d\n", printf(" %042% %042%"));
	// ft_printf("=>%d\n\n", ft_printf(" %042% %042%"));

	// printf("5\n");
	// printf("=>%d\n", printf("%042"));
	// ft_printf("=>%d\n\n", ft_printf("%042"));

	// printf("6\n");
	// printf("=>%d\n", printf("%0000%"));
	// ft_printf("=>%d\n\n", ft_printf("%0000%"));
}
