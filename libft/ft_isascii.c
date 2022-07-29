/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:49:07 by coder             #+#    #+#             */
/*   Updated: 2022/02/09 12:49:07 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <ctype.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*int main(void)
{
    //1 \/ 0x80 => €
    int a1 = 0x80;
    printf("1-mine: %d\n", ft_isascii(a1));
    int aa1 = 0x80;
    printf("1-original: %d\n\n", isascii(aa1));
    
    //2 \/ 0xc6 => Æ
    int a2 = 0xc6;
    printf("2-mine: %d\n", ft_isascii(a2));
    int aa2 = 0xc6;
    printf("2-original: %d\n\n", isascii(aa2));
    
    //3 \/ 0x83 => ƒ
    int a3 = 0x83;
    printf("3-mine: %d\n", ft_isascii(a3));
    int aa3 = 0x83;
    printf("3-original: %d\n\n", isascii(aa3));
    
    //4
    char a4 = 'k';
    printf("4-mine: %d\n", ft_isascii(a4));
    char aa4 = 'k';
    printf("4-original: %d\n\n", isascii(aa4));
    
    //5
    char a5 = '4';
    printf("5-mine: %d\n", ft_isascii(a5));
    char aa5 = '4';
    printf("5-original: %d\n\n", isascii(aa5));

    return (0);
}*/