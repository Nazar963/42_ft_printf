/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc((len + 1) * sizeof(*p));
	if (!p)
		return (NULL);
	while (s[start] != '\0' && len)
	{
		*p = s[start];
		p++;
		start++;
		len --;
		i++;
	}
	*p = '\0';
	return (p - i);
}
/*int	main(void)
{
    char s1[] = "hello my loco";
    printf("%s\n", ft_substr(s1, 2, 5)); //str start len
    
    char s2[] = "hello my loco";
    printf("%s\n", ft_substr(s2, 5, 2));
    
    char s3[] = "hello my loco";
    printf("%s\n", ft_substr(s3, 4, 15));
    
    char s4[] = "hello my loco";
	printf("%s\n", ft_substr(s4, 0, 13));
}*/