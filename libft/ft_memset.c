/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	char			car;

	car = (char)c;
	p = (unsigned char *)s;
	if (s == NULL)
		return (NULL);
	while (n > 0)
	{
		if (*p == 0)
		{
			break ;
		}
		*p = car;
		p++;
		n--;
	}
	return (s);
}
/*int main(void)
{
	char str[5] = "hello";
	char br[5] = "hello";
	   
	ft_memset(str + 1, '*', 3);
	printf("my: %s\n", str);
	     
	memset(str + 1, '*', 3);
	printf("og: %s\n", str);

	ft_memset(br, '*', 1);
	printf("my: %s\n", br);
	     
	memset(br, '*', 1);
	printf("og: %s\n", br);
}*/
