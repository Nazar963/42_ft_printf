/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:07 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 12:49:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	while (*s && *s != (char)c)
	{
		s++;
	}
	if (*s == '\0')
		return (NULL);
	while (*s != (char)c)
	{
		s--;
	}
	return ((char *)s);
}
/*int main(void)  
{
    char sd[] = "fsad3a2";
    printf("mine: %s \n", ft_strrchr(sd, 'd'));
    char s[] = "fsad3a2";
    printf("originale: %s \n", strrchr(s, 'd'));

    char sdq[] = "fsad3a2";
    printf("mine: %s \n", ft_strrchr(sdq, 'f'));
    char sq[] = "fsad3a2";
    printf("originale: %s \n", strrchr(sq, 'f'));

    char sdw[] = "fsad3a2";
    printf("mine: %s \n", ft_strrchr(sdw, '2'));
    char sw[] = "fsad3a2";
    printf("originale: %s \n", strrchr(sw, '2'));

    char sdd[] = "fsad3a2";
    printf("mine: %s \n", ft_strrchr(sdd, 'z'));
    char ss[] = "fsad3a2";
    printf("originale: %s \n", strrchr(ss, 'z'));

    char sda[] = "fsad3a2";
    printf("mine: %s \n", ft_strrchr(sda, '\0'));
    char sa[] = "fsad3a2";
    printf("originale: %s \n", strrchr(sa, '\0'));
    
    return (0);    
}*/
