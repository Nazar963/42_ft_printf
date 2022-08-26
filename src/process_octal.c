/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:53:49 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/23 10:58:44 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

static char	*allocation(char *digits)
{
	char	*holder;

	holder = (char *)malloc(sizeof(digits) * sizeof(*holder));
	if (!holder)
		return (NULL);
	return (holder);
}

static char	*digits_allocation(void)
{
	char	*digits;

	digits = (char *)malloc(36 * sizeof(*digits));
	if (!digits)
		return (NULL);
	return (digits);
}

static char	*reverse(char *ptr, size_t length)
{
	char	*str;
	char	*end;
	char	tmp;

	str = ptr;
	if (ptr && length)
	{
		end = ptr + length - 1;
		while (end > str)
		{
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
	return (ptr);
}

void	process_octal(unsigned int n, t_hint *loco)
{
	char	*digits;
	size_t	count;
	char	*holder;

	digits = digits_allocation();
	digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVXYZ";
	count = 0;
	holder = allocation(digits);
	while (n)
	{
		holder[count++] = digits[((unsigned)n) % 8];
		n = (unsigned)n / 8;
	}
	holder[count] = '\0';
	loco->count += count;
	ft_putstr_fd(reverse(holder, count), 1);
	free (holder);
}
