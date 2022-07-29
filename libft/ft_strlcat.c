/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

static int	str_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	src_length;
	size_t	dst_length;
	size_t	i;

	src_length = str_length(src);
	dst_length = str_length(dest);
	i = 0;
	if (size < 1)
		return (src_length + size);
	dest += dst_length;
	while (src[i] && i + dst_length < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	if (size < dst_length)
		return (src_length + size);
	else
		return (dst_length + src_length);
}
/*int main()
{
	char first[] = "This is "; //8
	char last[] = "a potentially long string"; //25
	int r;
	int size = 34;
	char buffer[size];

	strcpy(buffer,first);
	r = ft_strlcat(buffer,last,size);

	puts(buffer);
	printf("Value returned: %d\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");
	return(0);
}*/
