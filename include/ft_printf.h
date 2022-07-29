/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:51:32 by naal-jen          #+#    #+#             */
/*   Updated: 2022/07/28 19:52:26 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdint.h>// uintptr_t 
# include	<unistd.h>// write
# include	<stdlib.h>// malloc free
# include	<stdarg.h>// va_start va_arg va_copy va_end va_list

typedef struct s_hint
{
	int	count;
}		t_hint;

int		ft_printf(const char *str, ...);
void	ifpointer(unsigned long number, t_hint *loco);
void	ifhex(unsigned int number, char character, t_hint *loco);
char	*ft_itoa_mod(unsigned int n, t_hint *loco);
char	*ft_itoa_int(long int n, t_hint *loco);

#endif