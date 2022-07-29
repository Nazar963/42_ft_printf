/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;

	p = (char *)malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_memset(p, 0, nmemb * size);
	return (p);
}
/*int main(void)
{
    char str[] = "hello";
	printf("before: %s\n", str);
    ft_calloc(ft_strlen(str), sizeof(*str));
    printf("my: %s\n\n", str);
    
    char loco[] = "hello";
    printf("before: %s\n", loco);
	calloc(ft_strlen(loco), sizeof(*loco));
    printf("og: %s\n", loco);
}*/
