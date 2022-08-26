/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:51:32 by naal-jen          #+#    #+#             */
/*   Updated: 2022/08/26 21:17:43 by naal-jen         ###   ########.fr       */
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
	int		count;
	int		width;
	char	type[2];
	int		inc;
	int		processed;
}		t_hint;

int			ft_printf(const char *str, ...);
void		ifpointer(unsigned long number, t_hint *loco);
void		ifhex(unsigned int number, char cha, t_hint *loco);
void		number(long int n, t_hint *loco);
void		number_unsigned(unsigned n, t_hint *loco);
void		stringo(char *string, t_hint *loco);
void		me_char(va_list args, t_hint *loco);
void		process_octal(unsigned int n, t_hint *loco);
void		process_hash_flag(va_list args, t_hint *loco);
t_hint		*my_struct(void);
int			*new_i(void);
int			width_process(const char *str, t_hint *loco, int i);
int			left_process(const char *str, t_hint *loco, int i);
int			leading_process(const char *str, t_hint *loco, int i);
int			me_space(t_hint *loco, int i);
int			me_plus(t_hint *loco, int i);
int			me_hash(va_list args, t_hint *loco, const char *str, int i);
void		width_percent(const char *str, t_hint *loco, int *i);

#endif