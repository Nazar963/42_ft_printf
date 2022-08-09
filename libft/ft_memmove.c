/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:44:37 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/04 17:44:44 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*pdest;
	const char		*psrc;
	char			*tmp;

	i = 0;
	pdest = (char *)dest;
	psrc = (const char *)src;
	tmp = (char *)malloc(sizeof(*tmp) * n);
	if (!tmp)
		return (NULL);
	while (i < n)
	{
		*(tmp + i) = *(psrc + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*(pdest + i) = *(tmp + i);
		i++;
	}
	free (tmp);
	return (dest);
}
/*int	main(void)
{
	//my ft_memmove
	char cSrc[] = "loco is loco";
	char cDest[100];

	ft_memmove(cDest, cSrc, 13);
	printf("mine: %s\n", cDest);

	//og memmove
	char sSrc[] = "loco is loco";
	char sDest[100];

	memmove(sDest, sSrc, 13);
	printf("og: %s\n", sDest);

	//my ft_memmove
	int iSrc[] = {10, 20, 30, 40, 50};
	int n = sizeof(iSrc)/sizeof(iSrc[0]);
	int iDest[n], index = 0;

	ft_memmove(iDest, iSrc, sizeof(iSrc));
	printf("\nmine array: ");

	for (index=0; index<n; index++)
	{
		printf("%d ", iDest[index]);
	}

	//og memmove
	int wSrc[] = {10, 20, 30, 40, 50};
	int wn = sizeof(wSrc)/sizeof(wSrc[0]);
	int wDest[wn], windex = 0;

	memmove(wDest, wSrc, sizeof(wSrc));
	printf("\nog array: ");

	for (windex=0; windex<wn; windex++)
	{
		printf("%d ", wDest[windex]);
	}
	printf("\n");
	
	return (0);
}*/
