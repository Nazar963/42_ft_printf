/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*nsrc;
	char	*ndest;
	size_t	i;

	nsrc = (char *)src;
	ndest = (char *)dest;
	i = 0;
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	ndest[i] = '\0';
	return (ndest);
}
/*int main()
{
   char csrc[] = "loco is loco";
   char cdest[100];
   ft_memcpy(cdest, csrc, strlen(csrc)+1);
   printf("string: %s\n", cdest);
  
   int isrc[] = {10, 20, 30, 40, 50};
   int n = sizeof(isrc)/sizeof(isrc[0]);
   int idest[n], i;
   ft_memcpy(idest, isrc,  sizeof(isrc));
   printf("array: ");
   for (i=0; i<n; i++)
     printf("%d ", idest[i]);
   printf("\n");
   return 0;
}*/
/*int main () {
   const char src[50] = "http://www.tutorialspoint.com";
   char dest[50];
   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   memcpy(dest, src, strlen(src)+1);
   printf("After memcpy dest = %s\n", dest);
   
   return(0);
}*/
