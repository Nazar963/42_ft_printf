/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
//0#include <stdio.h>

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_rev(int *tab, int i, int fd)
{
	int		j;

	j = fd;
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar(tab[i] + '0', j);
		i--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		a[10];
	long	nbr;
	int		i;
	int		j;

	i = 0;
	j = fd;
	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-', j);
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		ft_putchar(nbr + '0', j);
		return ;
	}
	while (nbr > 0)
	{
		a[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	ft_rev(a, i, j);
}
/*int main(void)
{
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(-0, 1);
	printf("\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n");
	ft_putnbr_fd(-2147483648, 1);
}*/