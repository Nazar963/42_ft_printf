/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:07 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 12:49:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;

	d = dst;
	s = src;
	n = size;
	if (n != 0)
	{
		while (--n != 0)
		{
			*d++ = *s++;
			if (*d == '\0' && *s == '\0')
				break ;
		}
	}
	if (n == 0)
	{
		if (size != 0)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}
/*int main(void)
{
    //1
    char s[] = "hello yellow";
    char d[] = "bellow";
    printf("1-mine: %ld\n", ft_strlcpy(d, s, sizeof(d)));
    printf("1-mine: %s\n", d);
    char sa[] = "hello yellow";
    char da[] = "bellow";
    printf("1-original: %ld\n", strlcpy(da, sa, sizeof(da)));
    printf("1-original: %s\n\n", da);

    //2
    char s2[] = "hello yellow";
    char d2[2];
    printf("2-mine: %ld\n", ft_strlcpy(d2, s2, sizeof(d2)));
    printf("2-mine: %s\n", d2);
    char sa2[] = "hello yellow";
    char da2[2];
    printf("2-original: %ld\n", strlcpy(da2, sa2, sizeof(da2)));
    printf("2-original: %s\n\n", da2);

    //3
    char s3[] = "hello yellow";
    char d3[] = "bellow";
    printf("3-mine: %ld\n", ft_strlcpy(d3, s3, 5));
    printf("3-mine: %s\n", d3);
    char sa3[] = "hello yellow";
    char da3[] = "bellow";
    printf("3-original: %ld\n", strlcpy(da3, sa3, 5));
    printf("3-original: %s\n\n", da3);

    //4
    char s4[] = "hello yellow";
    char d4[] = "bellow";
    printf("4-mine: %ld\n", ft_strlcpy(d4, s4, 0));
    printf("4-mine: %s\n", d4);
    char sa4[] = "hello yellow";
    char da4[] = "bellow";
    printf("4-original: %ld\n", strlcpy(da4, sa4, 0));
    printf("4-original: %s\n\n", da4);

    return (0);
}*/
