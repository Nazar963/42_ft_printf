/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
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

static	char	*ft_strcat(char *dest, const char *src)
{
	char	*start;

	start = dest;
	while (*start != '\0')
	{
		start++;
	}
	while (*src != '\0')
	{
		*start++ = *src++;
	}
	*start = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*p;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(len * sizeof(*p));
	if (!p)
		return (NULL);
	p = ft_strcat((char *)s1, (char *)s2);
	return (p);
}
/*int main(void)
{
	char	s1[] = "hello";
	char	s2[] = " loco";
	printf("%s\n", ft_strjoin(s1, s2));

	return (0);
}*/