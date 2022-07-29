/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" // ft_stlen
#include <stdlib.h> // malloc
//#include <stdio.h> // printf for testing
//#include <string.h> // strdup for testing

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc(sizeof(*p) * ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int main(void)
{
    char s[] = "hello";
    printf("%s\n", ft_strdup(s));
    
	char sd[] = "hello";
	printf("%s\n", strdup(sd));
}*/
