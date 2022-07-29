/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	*char_found;
	unsigned char	char_to_find;

	p = (unsigned char *)s;
	char_found = NULL;
	char_to_find = (unsigned char)c;
	while (s != NULL)
	{
		if (*p != char_to_find)
		{
			p++;
		}
		else
		{
			char_found = p;
			break ;
		}
		n--;
	}
	return (char_found);
}
/*int main()
{
    char s[] = "loco is loco";
    
    char *ptr = ft_memchr(s,'c',sizeof(s));
    if (ptr != NULL)
    {
        printf ("'c' found with mine: %ld.\n", ptr - s + 1);
        printf ("found:  %s\n", ptr);
    }
    else
        printf ("not found\n");

    char sh[] = "loco is loco";
    
    char *ptrh = memchr(sh,'c',sizeof(sh));
    if (ptrh != NULL)
    {
        printf ("'c' found with og: %ld.\n", ptrh - sh + 1);
        printf ("found:  %s\n", ptrh);
    }
    else
        printf ("not found\n");
    return (0);
}*/
