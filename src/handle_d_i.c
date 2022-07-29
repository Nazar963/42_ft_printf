/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:37:24 by naal-jen          #+#    #+#             */
/*   Updated: 2022/07/28 20:05:38 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_printf.h"

static char	*positive_number(char *ptr, int i)
{
	int		j;
	char	tab[1];

	j = 0;
	while (j < i / 2)
	{
		tab[0] = ptr[i - 1 - j];
		ptr[i - 1 - j] = ptr[j];
		ptr[j] = tab[0];
		j++;
	}
	return (ptr);
}

static char	*reverse_string(char *ptr, int i)
{
	int		j;
	int		k;
	char	tab[1];

	k = 0;
	if (i == 1 && ptr[0] == '0')
	{
		return (ptr);
	}
	if (ptr[0] == '-')
	{
		j = 1;
		while (j <= i / 2)
		{
			tab[0] = ptr[i - 1 - k];
			ptr[i - 1 - k] = ptr[j];
			ptr[j] = tab[0];
			j++;
			k++;
		}
		return (ptr);
	}
	return (positive_number(ptr, i));
}

static int	count_digits(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_int(long int n, t_hint *loco)
{
	char		*ptr;
	int			i;
	int			j;

	i = count_digits(n);
	j = 0;
	ptr = (char *)malloc((i + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	if ((n == 0 && ++loco->count) || (n == -0 && ++loco->count))
		return ("0");
	if (n < 0 && i++)
	{
		ptr[j++] = '-';
		n = -n;
	}
	while (n)
	{
		ptr[j++] = n % 10 + '0';
		n = n / 10;
	}
	ptr[j] = '\0';
	loco->count += j;
	return (reverse_string(ptr, i));
}

char	*ft_itoa_mod(unsigned int n, t_hint *loco)
{
	char		*ptr;
	int			i;
	int			j;

	i = count_digits(n);
	j = 0;
	ptr = (char *)malloc((i + 1) * sizeof(*ptr));
	if (!ptr)
		return (NULL);
	if ((n == 0 && ++loco->count))
		return ("0");
	while (n)
	{
		ptr[j++] = n % 10 + '0';
		n = n / 10;
	}
	ptr[j] = '\0';
	loco->count += j;
	return (reverse_string(ptr, i));
}
