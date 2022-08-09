/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:37:24 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/09 18:11:23 by naal-jen         ###   ########.fr       */
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

void	number_unsigned(int n, t_hint *loco)
{
	char	*string;

	string = ft_itoa_mod(n);
	ft_putstr_fd(string, 1);
	loco->count += ft_strlen(string);
	free (string);
}

void	number(int n, t_hint *loco)
{
	char	*string;

	string = ft_itoa(n);
	ft_putstr_fd(string, 1);
	loco->count += ft_strlen(string);
	free (string);
}
