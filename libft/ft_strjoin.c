/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:46:22 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 19:41:40 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdlib.h> // malloc
// #include <stdio.h> // printf for testing

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*p;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = (char *)malloc(len * sizeof(*p));
	if (!p)
		return (NULL);
	while (*s1 != '\0')
	{
		*p++ = *s1++;
	}
	while (*s2 != '\0')
	{
		*p++ = *s2++;
	}
	*(p + len) = '\0';
	return (p - len + 1);
}
/*int main(void)
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	printf("%s\n", ft_strjoin(s1, s2));
	
	char	as1[] = "lorem ipsum";
	char	as2[] = "dolor sit amet";
	as1[0] = '\0';
	printf("%s\n", ft_strjoin(as1, as2));
	
	char	ss1[] = "lorem ipsum";
	char	ss2[] = "dolor sit amet";
	ss2[0] = '\0';
	printf("%s\n", ft_strjoin(ss1, ss2));
	
	char	ws1[] = "lorem ipsum";
	char	ws2[] = "dolor sit amet";
	ws1[0] = '\0';
	ws2[0] = '\0';
	printf("%s\n", ft_strjoin(ws1, ws2));

	return (0);
}*/