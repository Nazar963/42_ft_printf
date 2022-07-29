/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> // malloc
//#include <stdio.h> // printf for testing

static int	first_trim(char const *s1, char const *set, size_t j, int n)
{
	n = 0;
	while (s1[n])
	{
		if (s1[n] != set[j])
		{
			j = 0;
			while (set[j] != s1[n])
			{
				if (set[j] == '\0')
				{
					return (n);
				}
				j++;
			}
		}
		while (s1[n] == set[j])
		{
			n++;
		}
		j++;
	}
	return (0);
}

static int	last_trim(char const *s1, char const *set, size_t j, int fin)
{
	fin = ft_strlen(s1);
	while (fin)
	{
		if (s1[fin] != set[j])
		{
			j = 0;
			while (set[j] != s1[fin])
			{
				if (set[j] == '\0')
				{
					return (fin);
				}
				j++;
			}
		}
		while (s1[fin] == set[j])
		{
			fin--;
		}
		j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	j;
	int		n;
	int		fin;
	char	*p;

	j = 0;
	p = (char *)malloc((ft_strlen(s1) + 1) * sizeof(*p));
	if (!p)
		return (NULL);
	n = 0;
	fin = 0;
	n = first_trim(s1, set, j, n);
	fin = last_trim(s1, set, j, fin);
	while (n <= fin)
	{
		p[j++] = s1[n++];
	}
	p[j] = '\0';
	return (p);
}

/*int main(void)
{
	//1
	const char *a1 = "bed";
	printf("1: %s\n", ft_strtrim("bedhelbedlobed", a1));

	//2
	const char *a2 = "bed";
	printf("2: %s\n", ft_strtrim("bedbedhelbedlobedbed", a2));

	//3
	const char *a3 = "fdsafdsafdsa";
	printf("3: %s\n", ft_strtrim("fdsafdsafdsahelfdsafdsafdsalofdsafdsafdsa", a3));

	//4
	const char *a4 = "v v v";
	printf("4: %s\n", ft_strtrim("v vhellov v", a4));

	//5
	const char *a5 = "1234567";
	printf("5: %s\n", ft_strtrim("1234bedhelbedlobed1234567", a5));

	//6
	const char *a6 = "g";
	printf("6: %s\n", ft_strtrim("gbgegdghgeglgbgegdglgogbgegdg", a6));

	//7
	const char *a7 = "bed";
	printf("7: %s\n", ft_strtrim("bbbbeddddhellobbbbedddd", a7));

	//8
	const char *a8 = "bed";
	printf("8: %s\n", ft_strtrim("bdbebdbedbdbeedbdbhellobbbbedddd", a8));
}*/